def job_sequencing(job):
    n = len(job)
    timeslot = [-1] * n

    selection_sort(job)
    print(job)

    for i in range(n):
        deadline = job[i][1]
        for j in range(min(deadline,n)-1,-1,-1):
            if timeslot[j] == -1:
                timeslot[j] = i;
                break

    # for i in timeslot:
    #     if i != -1:
    #         print("|",job[i],end="\t")
    #     else:
    #         print("|    ----",end="\t")
    # print("|")
    # for i in range(n+1):
    #     print(i,end="\t\t")

    schedule = [job[i] for i in timeslot if i != -1]
    return schedule 

def selection_sort(job):
    n = len(job)
    for i in range(n-1):
        min = i
        for j in range(i+1,n): 
            if job[min][0] < job[j][0]:
                min = j
        job[min],job[i] = job[i],job[min]


job = [(5,3),(6,2),(10,5),(1,2),(2,2)]

print("\n\nResult: ",job_sequencing(job))
