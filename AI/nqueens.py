def issafe(arr,x,y,n):
    for row in range(x):
        if(arr[row][y])==1:
            return False
    row=x
    col=y
    #diagonal
    while row>=0 and col>=0:
        if arr[row][col]==1:
            return False
        row-=1
        col-=1
    row=x
    col=y
    
    while row>=0 and col<n:
        if arr[row][col]==1:
            return False
        row-=1
        col+=1

    return True

def nqueen (arr,x,n):
    if x>=n:
        return True
    
    for col in range(n):
        if issafe(arr,x,col,n):
            arr[x][col]=1
            if nqueen(arr,x+1,n):
                return True
            arr[x][col]=0

    return False

def main():
    n=int(input("enter num of queens"))
    arr=[[0]*n for i in range(n)]

    if nqueen(arr,0,n):
        for i in range(n):
            for j in range(n):
                print(arr[i][j],end=" ")
            print()
if __name__=='__main__':
    main()