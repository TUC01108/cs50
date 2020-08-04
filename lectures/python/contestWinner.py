import csv
import random

s=open("IGexport2.csv","r")
m=s.readlines()
l=[]
for i in range(0,len(m)-1):
    x=m[i]
    z=len(x)
    a=x[:z-1]
    l.append(a)
l.append(m[i+1])
o=random.choice(l)
print(o)
