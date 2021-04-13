import matplotlib
import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
ax = fig.add_subplot(111)


def plotterFunc(x_left, x_right, y_bottom, y_top,p):
    low = (x_left, y_bottom)

    rect1 = matplotlib.patches.Rectangle(low, abs(x_right - x_left), abs(y_top - y_bottom),
                                         edgecolor='black', facecolor="none")

    ax.add_patch(rect1)

    plt.xlim([-p-1, p+1])
    plt.ylim([-p-1, p+1])

def horizontalPlotter(a,b,c):
    x=[list[1],list[2]]
    y=[list[0],list[0]]
    plt.plot(x,y,"r")

def verticalPlotter(a,b,c):
    x=[list[0],list[0]]
    y=[list[1],list[2]]
    plt.plot(x,y,"r")




f = open("input.txt", "r")
lines=f.readlines()
for line in lines:
    list=line.split(',')
    for i in range(len(list)):
        list[i]=int(list[i])
    plotterFunc(int(list[0]),int(list[1]),int(list[2]),int(list[3]),max(list))

h=open("horizontal.txt","r")
lines=h.readlines()
for line in lines:
    list=line.split(',')
    for i in range(len(list)):
        list[i]=int(list[i])
    horizontalPlotter(list[0],list[1],list[2])

v=open("Hvertical.txt","r")
lines=v.readlines()
for line in lines:
    list=line.split(',')
    for i in range(len(list)):
        list[i]=int(list[i])
    verticalPlotter(list[0],list[1],list[2])





plt.show()

#plotterFunc(1, 6, 2, 9)
#plotterFunc(4, 11, 4, 15)
#plotterFunc(5, 10, 6, 19)
#x1=[1,6]
#y1=[2,2]
#plt.plot(x1,y1,"g")
#plt.show()



