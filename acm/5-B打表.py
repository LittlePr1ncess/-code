a={}
a[1]=1
a[0]=1
s='{'
for i in range(2,251):
    a[i]=a[i-1]+2*a[i-2]
for i in range(0,251):
    s+='\"'+str(a[i])+'\",'
s+='}'
print(s)