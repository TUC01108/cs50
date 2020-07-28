import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    #rows = db.execute("SELECT * FROM history GROUP BY timestamp HAVING id2 = :id2", id2=session['user_id'])
    #stock = lookup(db.execute("SELECT symbol FROM history GROUP BY timestamp HAVING id = 1"))
    stocks = db.execute("SELECT symbol, shares, name FROM history WHERE id = :id", id=session['user_id'])
    result = db.execute("SELECT cash FROM users WHERE id = :id", id=session['user_id'])
    total_cash = float(result[0]['cash'])
    total_total = total_cash
    for stock in stocks:
        symbol = str(stock["symbol"])
        quote = lookup(symbol)
        price = 4555
        shares = int(stock["shares"])
        name = stock["name"]
        total_val = float(price * shares)
        total_total += total_val
    return render_template("index.html", stocks=stocks, cash=total_cash, total_total=total_total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")
    else:
        if not request.form.get("symbol"):
            return apology("Must enter symbol")
        if not request.form.get("shares") and request.form.get("shares") > 0:
            return apology("Must enter valid amount of shares")
        stock = lookup(request.form.get("symbol"))
        if stock == None:
            return apology("Could not locate stock")

        result = db.execute("SELECT cash FROM users WHERE id = :id",
                          id=session["user_id"])
        cash = float(result[0]['cash'])

        symbol = request.form.get("symbol")

        quote = lookup(symbol)

        numShares = int(request.form.get("shares"))

        amount = float(numShares * quote['price'])

        # Ensure user has enough cash to buy stock
        if not cash >= amount:
            return apology("Can't afford", 403)

        # Insert purchase into database
        db.execute("INSERT INTO history (id, symbol, shares, price, name) VALUES (:id, :symbol, :shares, :price, :name)", id=session["user_id"],
                    symbol=quote["symbol"], shares=numShares, price=quote['price'], name=quote["name"])

        # Update total cash
        db.execute("UPDATE users SET cash = cash - :amount WHERE id = :id", id=session['user_id'], amount=amount)

        # Redirect user to index
        return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    else:
        if not request.form.get("symbol"):
            return apology("Must enter symbol")
        stock = lookup(request.form.get("symbol"))
        if stock == None:
            return apology("Could not locate stock")
        return render_template("quoted.html", stock=stock)


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Ensure passwords match
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords must match", 403)

        # Query database for possible username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username does not exist
        if len(rows) == 1:
            return apology("username already exists", 403)

        # Insert username and password into database
        db.execute("INSERT INTO users (username, hash) VALUES (:username, :hash)",
                    username=request.form.get("username"), hash=generate_password_hash(request.form.get("password")))

        # Query database for confirmed username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
