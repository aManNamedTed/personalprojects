import csv

with open('cashierDetails.csv', 'r') as csvfile:
    cashierDetails = csv.reader(csvfile, delimiter=',')
    uidList = []        #(attr + "List") for verboseness
    nameList = []       #(attr + "List") for verboseness
    passwordList = []   #(attr + "List") for verboseness
    for row in cashierDetails:
        uid = row[0]
        name = row[1]
        password = row[2]

        uidList.append(uid)
        nameList.append(name)
        passwordList.append(password)

        print("{}\t{}\t{}".format(uid, name, password))


i = "001"

for x in uidList[:]:
    print(x)

    if i in uidList:
        print("001 has been matched")
