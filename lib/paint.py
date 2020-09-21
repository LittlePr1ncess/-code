
import matplotlib.pyplot as plt
import numpy as np
import math

#plt.title("哈希表运行效率与时间复杂度期望对比图") 
plt.xlabel("N") 
plt.ylabel("time/ms") 
#x=np.array([1999,2000,2003,2004,2005,2006,2007,2008,2009,2011,2012,2013,2014,2015,2016,2017,2018])
#y=np.array([10.46 ,11.06,10.73,11.32,11.14,11.26,11.36,11.13,11.24,11.48,10.94,10.58,11.43,11.99,11.49,11.66,12.48])
#y2 = np.array([0, -1, -1.57, -1.36, -0.49, 0.94, -0.45, 0, -0.42, -0.27, -0.23, -0.41, -0.24, -0.27, -0.15, -0.18, -0.82])
x = np.array([10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000])
y = np.array([0, 2, 1, 2, 3, 2, 4, 5, 5, 8, 13, 31, 31, 51, 94, 68, 82, 103])
y2=np.array([3,7,11,13,21,32,36,63,51,64,167,238,330,446,580,701,839,984])
'''
seed=np.random.normal(size=(17),loc=0.5, scale=1)
j=0
#print(seed[1])
for i in y:
    
    #print(j)
    y[j]=i+(j-1)*0.05*seed[j]
    
    print(x[j],y[j])
    j+=1
'''
#plt.plot(x,1500*(1-pow(math.e,-0.261*x)),'r',
#         x,1000+0.515*pow(x,1.945),'b')#,
         #x,1300*(1-pow(math.e,-0.303*x)),'g',
         #x,2000*(1-pow(math.e,-0.14*x)),'gold',
         #x,6000*(1-pow(math.e,-0.05*x)),'pink')
#plt.plot(11.25,270,'ob')
#plt.text(12,260,"[11.25,270]")
plt.grid(True)
for i in range(0,18):
    x[i]*=10
#plt.axis([0,15,0,300])
plt.plot(x, y, 'b')
plt.plot(x,y2,'r')
#plt.plot(x,y2,'r')
plt.show()
'''
import numpy as np 
from matplotlib import pyplot as plt 
 
x = np.arange(0,15) 
y =  2  * x +  5 
plt.title("Matplotlib demo") 
plt.xlabel("x axis caption") 
plt.ylabel("y axis caption") 
plt.plot(x,2*x,'r-') 
plt.show()'''