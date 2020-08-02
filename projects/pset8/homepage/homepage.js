function guess()
            {
                let thomasAge = 29;
                let age = document.querySelector('#age').value;
                if (age === '')
            {
                age = 'an unknown age!';
            }
                if ((age - thomasAge) >= 0)
                {
                    document.querySelector('#result').innerHTML = 'You are ' + (age - thomasAge) + ' year(s) older than Thomas!';
                }
                else
                {
                    document.querySelector('#result').innerHTML = 'You are ' + (thomasAge - age) + ' year(s) younger than Thomas!';
                }
            }
            function facts()
            {
                let facts30 = ' Most bodily functions peak shortly before age 30 and then begin a gradual but continuous decline. However, even with this decline, most functions remain adequate because most organs start with considerably more functional capacity than the body needs (functional reserve). The amount of muscle tissue (muscle mass) and muscle strength tend to decrease beginning around age 30 and continuing throughout life. Some of the decrease is caused by physical inactivity and decreasing levels of growth hormone and testosterone, which stimulate muscle development. The kidneys tend to become smaller because the number of cells decreases. Less blood flows through the kidneys, and at about age 30, they begin to filter blood less well. As years pass, they may remove waste products from the blood less well. They may excrete too much water and too little salt, making dehydration more likely.';
                let facts40 = ' During their 40s, most people notice that seeing objects closer than 2 feet becomes difficult. This change in vision, called presbyopia, occurs because the lens in the eye stiffens. ';
                let facts50 = ' By age 75, the percentage of body fat typically doubles compared with what it was during young adulthood. Too much body fat can increase the risk of health problems, such as diabetes. The distribution of fat also changes, changing the shape of the torso. A healthy diet and regular exercise can help older people minimize increases in body fat. On average, 60-year-olds need 3 times more light to read than 20-year-olds. Generally, when people are in their 50s, the ability to taste and smell starts to gradually diminish.';
                let facts20 = ' As you go from your 20s to 30s you may notice a slowing metabolism, hormonal upheaval, depression or a serious mental disorder... As you can tell that was from a womens health website. Yikes! I think its important to understand your health is not always in your control, but we do have more to say about it then most magazines or news sites will tell us. We have a choice to shape our future body, mind, and metabolism all with making simple decisions probably 30% of the time. If something does go wrong then it is important to look for options on what you can do and start with baby steps towards getting there.';
                let facts10 = ' you should have NOTHING health-wise to worry about! : )';
                let age = document.querySelector('#age').value;
                if (age >= 30 & age < 40)
                {
                    document.querySelector('#newish').innerHTML = 'Things to think about at ' + (age) + ' year(s) old:' + facts30;
                }
                else if (age >= 40 & age < 50)
                {
                    document.querySelector('#newish').innerHTML = 'Things to think about at ' + (age) + ' year(s) old:' + facts40;
                }
                else if (age >= 50)
                {
                    document.querySelector('#newish').innerHTML = 'Things to think about at ' + (age) + ' year(s) old:' + facts50;
                }
                else if (age >= 20 & age < 30)
                {
                    document.querySelector('#newish').innerHTML = 'Things to think about at ' + (age) + ' year(s) old:' + facts20;
                }
                else
                {
                    document.querySelector('#newish').innerHTML = 'At ' + (age) + ' year(s) old' + facts10;
                }
            }