import matplotlib.pyplot as plt
import numpy as np
import sys
import os

f = open('valores.dat', 'r')
listu = f.readlines()
f.close()

arrayu = np.array(listu)

tf = 201
u = np.array_split(arrayu, tf)


for i in range(tf-1):

    plt.figure()
    plt.plot(u[i])
    plt.ylim(-1, 1)
    name = 'u_%05d.png' %i
    plt.savefig(name)
    plt.close()

os.system('convert -delay 8 -loop 0 *png cuerda.gif')
os.system('rm *.png')
