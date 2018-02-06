import datetime

def stub():
    calcTax(300)
    return

#Print Receipt Header
def printHeader():
    now = datetime.datetime.now()
    registerDetails = open("registerDetails", "r")
    print("=======================================")
    print("The Store")
    print("123 Avenue")
    print("City, State 12345")
    print("555.555.5555")
    print("Where Bargains Live!")
    print()
    registerDetails.close()
    return

#Calculate Tax
def calcTax(subtotal):
    registerDetails = open("registerDetails", "r")
    s = registerDetails.readlines()
    if(s.find("Tax: " ))


    return 4#(subtotal + (subtotal * tax_rate))
    registerDetails.close()

#A Sale
def sale():
    return

#B Return Item
def returnItem():
    return

#C Close Register
def closeRegister():
    return

#D Duplicate Receipt
def duplicateReceipt():
    return

#E No Sale
def noSale():
    print("Register opens")
    input("Press enter to close the register...")
    return

#F Employee Sale
def employeeSale():
    return

#G Employee Return
def employeeReturn():
    return

#H Loans
def loans():
    return

#I Price Check
def priceCheck():
    return

#J Inquiries
def inquiries():
    return

#K Opening Balance
def openingBalance():
    return

#L Closing Counts
def closingCounts():
    return

#M Gift Receipt
def giftReceipt():
    return

def menu():
    print("David's Universal POS")
    print("""
        #A: Sale
        #B: Return
        #C: Close Register
        #D: Duplicate Receipt
        #C: Post Void
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
        sale()
    elif ((ans == "B") or (ans == "b")):
        returnItem()
    elif ((ans == "C") or (ans == "c")):
        closeRegister()
    elif ((ans == "D") or (ans == "d")):
        duplicateReceipt()
    elif ((ans == "E") or (ans == "e")):
        noSale()
    elif ((ans == "F") or (ans == "f")):
        employeeSale()
    elif ((ans == "G") or (ans == "g")):
        employeeReturn()
    elif ((ans == "H") or (ans == "h")):
        loans()
    elif ((ans == "I") or (ans == "i")):
        priceCheck()
    elif ((ans == "J") or (ans == "j")):
        inquiries()
    elif ((ans == "K") or (ans == "k")):
        openingBalance()
    elif ((ans == "L") or (ans == "l")):
        closingCounts()
    elif ((ans == "M") or (ans == "m")):
        giftReceipt()
    elif ((ans == "N") or (ans == "n")):
        stub()
    else:
        input("Wrong option selection. Enter a valid option...")

    return True

loop = True
while loop:
    loop = menu()
    loop = False #run once only; remove after finish
