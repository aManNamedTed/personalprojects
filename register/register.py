import datetime         #for current date on receipt
import csv              #for csvfile reading

#Error function to minimize string reuse [is either missing or... etc]
def printError(string):
    print("{} is either missing or modified. Aborting...".format(string))

#Finds Tax Rate in the string from registerDetails
def findTax(string):
    if(string[0] == 'T' and string[1] == 'a' and string[2] == 'x'
    and string[3] == ':'):
        taxRate = float(string[4:])
    else:
        printError("Tax string")
    return taxRate

#Finds Receipt Number in the string from registerDetails
def findReceiptNumber(string):
    if(string[0] == 'R' and string[1] == 'e' and string[2] == 'c'
    and string[3] == 'e' and string[4] == 'i' and string[5] == 'p'
    and string[6] == 't' and string[7] == ' '):
        receiptNumber = str(string[16:])
    else:
        printError("Receipt Number")
        receiptNumber = -1

    return str(receiptNumber)

#Print Receipt Header
def printHeader(cashierNameParent):
    #initializing current date object, and string
    now = datetime.datetime.now()
    dateString = ("{}.{}.{}, {}:{}:{}".format(now.day,
    now.month, now.year, now.hour, now.minute, now.second))

    registerDetails = open("registerDetails", "r")
    stringifiedRegisterDetails = registerDetails.readlines()

    receiptNumber = findReceiptNumber(stringifiedRegisterDetails[0])
    taxRate = findTax(stringifiedRegisterDetails[1])
    cashierName = cashierNameParent

    print("=======================================")
    print("The Store")
    print("123 Avenue")
    print("City, State 12345")
    print("555.555.5555")
    print("Where Bargains Live!")
    print()
    print("Cashier:{}".format(cashierName))
    print("Transaction: {}".format(receiptNumber))
    print(dateString)
    registerDetails.close()
    return

#Calculate Tax 
def calcTax(subTotal, taxRate):
    return (subTotal * taxRate)

#Calculate Grand Total (subtotal + tax)
def calcGrandTotal(subTotal, taxAmount):
    return (subTotal + taxAmount)

#Calculates subtotal from a list passed into the function
def calcSubTotal(wantToPurchase):
    subTotal = 0.00 #need to init

    for i in range(len(wantToPurchase)):
        subTotal += float(wantToPurchase[i])

    return subTotal


#A Sale
def sale(cashierName):
    #prints header of receipt with cashier's name in cashier place
    printHeader(cashierName)

    #init lists to be utilized later
    itemIDList, itemNameList, itemPriceList = initInventory()

    #need to init a list for subtotal amount
    wantToPurchase = [] 

    # flag to keep loop going until a payment option is chosen
    finishedOrdering = False

    while(not finishedOrdering):
        sku = input("SKU (-1 to exit to payment): ")

        if(sku in itemIDList):
            skuIndex = itemIDList.index(str(sku))

            print("{}:{},{}".format(itemIDList[skuIndex], itemNameList[skuIndex], itemPriceList[skuIndex]))

            wantToPurchase.append(itemPriceList[skuIndex])
            print("Subtotal: {}".format(float(calcSubTotal(wantToPurchase))))
            if(sku == "-1"):
                finishedOrdering = True

        else:
            print("Item {} not found.".format(sku))



#initInventory, reads csv of inventory in log, and returns csv as list to the function calling it
def initInventory():
    with open('inventoryList.csv', 'r') as csvfile:
        inventoryList = csv.reader(csvfile, delimiter=',')
        itemIDList = []        #(attr + "List") for verboseness
        itemNameList = []      #(attr + "List") for verboseness
        itemPriceList = []     #(attr + "List") for verboseness
        for row in inventoryList:
            itemID = row[0]
            itemName = row[1]
            itemPrice = row[2]

            itemIDList.append(itemID)
            itemNameList.append(itemName)
            itemPriceList.append(itemPrice)
        csvfile.close()

    return itemIDList, itemNameList, itemPriceList

#B Return Item
def returnItem(cashierName):
    return

#C Close Register
def closeRegister(cashierName):
    print("Print summary of today's transactions")
    print("Register closed by {}.".format(cashierName))
    return

#D Duplicate Receipt
def duplicateReceipt(cashierName):
    return

#E No Sale
def noSale(cashierName):
    print("Register opens")
    input("Press enter to close the register...")
    return

#F Employee Sale
def employeeSale(cashierName):
    return

#G Employee Return
def employeeReturn(cashierName):
    return

#H Loans
def loans(cashierName):
    return

#I Price Check
def priceCheck(cashierName):
    return

#J Inquiries
def inquiries(cashierName):
    return

#K Opening Balance
def openingBalance(cashierName):
    return

#L Closing Counts
def closingCounts(cashierName):
    return

#M Gift Receipt
def giftReceipt(cashierName):
    return

#Initializes cashiers from read-only file in directory
#Returns 3 lists, uidList, nameList, passwordList, to be verified later
def initCashiers():
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
        csvfile.close()

    return uidList, nameList, passwordList

# Verify Login, grabs information from read-only list of employees
def verifyLogin(cashierNumber, cashierPassword):
    uidList, nameList, passwordList  = initCashiers()

    if (cashierNumber in uidList):
        cashierIndex = uidList.index(str(cashierNumber))
        if(int(cashierPassword) == int(passwordList[cashierIndex])):
            cashierName = nameList[cashierIndex]
            access = True
        else:
            print("Cashier UID or Cashier PW invalid.")
            cashierName = "VOID"
            access = False

    return access, cashierName

# Cashier Sign-in
def login():
    #no need to verify details, just spit out invalid login
    cashierNumber = input("Cashier Number: ")
    cashierPassword = input("Cashier Password: ")
    return verifyLogin(cashierNumber, cashierPassword)

# Transaction Selection
def menu():
    access, cashierName = login()

    #access kicks out any login that is invalid
    while (access):
        loop = True

        print("David's Universal POS")
        print("""
            #A: Sale
            #B: Return
            C: Close Register
            #D: Duplicate Receipt
            E: No Sale
            #F: Employee Sale
            #G: Employee Return
            #H: Loans
            #I: Price Check
            #J: Inquiries
            #K: Opening Balance
            #L: Closing Counts
            #M: Gift Receipt
        """)
        ans=input("Selection: ")
        if ((ans == "A") or (ans == "a")):
            sale(cashierName)
        elif ((ans == "B") or (ans == "b")):
            returnItem(cashierName)
        elif ((ans == "C") or (ans == "c")):
            closeRegister(cashierName)
        elif ((ans == "D") or (ans == "d")):
            duplicateReceipt(cashierName)
        elif ((ans == "E") or (ans == "e")):
            noSale(cashierName)
        elif ((ans == "F") or (ans == "f")):
            employeeSale(cashierName)
        elif ((ans == "G") or (ans == "g")):
            employeeReturn(cashierName)
        elif ((ans == "H") or (ans == "h")):
            loans(cashierName)
        elif ((ans == "I") or (ans == "i")):
            priceCheck(cashierName)
        elif ((ans == "J") or (ans == "j")):
            inquiries(cashierName)
        elif ((ans == "K") or (ans == "k")):
            openingBalance(cashierName)
        elif ((ans == "L") or (ans == "l")):
            closingCounts(cashierName)
        elif ((ans == "M") or (ans == "m")):
            giftReceipt(cashierName)
        else:
            input("Wrong option selection. Selection: ")
            loop = False

        return loop

loop = True
while loop:
    loop = menu()
    loop = False #run once only; remove after finish
