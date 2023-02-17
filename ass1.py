class hash:
    def __init__ (self):
        print("arranging hash table")


    def hash0(self,a):
        
        b=[]
        for i in range (a):
            b.append(0)
        return (b)

    def list(self,a):
        print("enter elements")
        b=[]
        for i in range (a):
            b.append(int(input()))
        return (b)

    def hash(self,a,h,n):
        for i in range (0,len(a)):
            d=(a[i]%n)
            if (h[d]!=0):
                for j in range(d,len(h)):
                    if (h[j]==0):
                        h[j]=a[i]
                        break
                    else:
                        continue
            else:
                h[d]=a[i]
        return (h)
   
    def display(self,c,n):
        i=0
        while(i<n):
            print(c[i])
            i=i+1

q=hash()
n=int(input("enter total no. of values in list :"))
l=q.list(n)
hn=int(input("enter hash table size"))
h=q.hash0(hn)
fh=q.hash(l,h,hn)
q.display(fh,hn)

