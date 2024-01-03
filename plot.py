import matplotlib
import tkinter
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt
import os, glob
import numpy as np
data = []
with open("result", 'r') as f: 
    data = (f.readlines())
x = [2**i for i in range(21)]
y1 = []
y2 = []
y3 = []
for line in data:
    if "YES" in line:
        continue
    if "NO" in line:
        print("NOT correct")
        break
    line = list(map(float,line.replace("\n","").split(" ")))
    y1.append(line[0])
    y2.append(line[1])
    y3.append(line[2])
plt.plot(x,y1,label='Sorted Array')
plt.plot(x,y2,label='Array of Sorted Arrays')
plt.plot(x,y3,label='Skiped List')
axs = plt.gca()
plt.xlabel("k")
plt.ylabel("Time(s)")
plt.title("graph 1")
axs.set_xscale("log",basex=2)
plt.legend()
plt.show()

