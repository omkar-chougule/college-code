def quick_sort(lst, low, high):
    if low < high:
        ind = split(lst, low, high)
        quick_sort(lst, low, ind - 1)
        quick_sort(lst, ind + 1, high)


def split(lst, low, high):
    index = low - 1
    for i in range(low, high):
        if lst[i] <= lst[high]:
            index += 1
            lst[i], lst[index] = lst[index], lst[i]
    lst[index + 1], lst[high] = lst[high], lst[index + 1]
    return index + 1


def enter_lst():
    n = int(input("Enter total number of students present:"))
    lst = []
    for i in range(n):
        rollno = int(input("Enter roll no.:"))
        lst.append(rollno)
    print("List entered is:", lst)
    return lst


while True:
    print("select which search method you would like to use:")
    print("1.Enter a new list")
    print("2.Exit code")
    ch = int(input("Enter your choice:"))
    if ch == 1:
        lst = enter_lst()
        quick_sort(lst, 0, len(lst)-1)
        print("The highest 5 scores are:")
        for i in range(-1, -6, -1):
            print(lst[i])
    elif ch == 2:
        break
    print("-" * 50)
print("Code exited")
