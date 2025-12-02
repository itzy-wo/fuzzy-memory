#mood tracker 
import pandas as pd
data = {}
data["Name"]=input("Please enter your Name")
input("So have u been today????Feel free to type anything u want")
data["studied so far?"] = input("Have u studied today?")
data["Studing hours"]=int(input("how long tell me in hours"))
data["break"]=input("did u take break?")
print("Quick tell me how u feel")
eneg_level=input(" 1.energetic 2.Consistent 3.mid 4.Low")
print("Your motivational score is tada!!")
match (eneg_level):
    case "energetic":
        print("Damn that's 100 out of 10 bitch😘")
        data["score"]=4
    case "Consistent":
        print("Good girl that's what u call my babe🤧")
        data["score"]=5
    case "mid":
        print("It's ok dear we can be tired alot of times🥺")
        data["score"]=3
    case "Low":
        print("NOw go dear rest ok it's time to sleep")
        data["score"]=2
df = pd.DataFrame([data])
print("Here take the excel in steriods",df,sep='\n')
df.to_csv("new.csv",index=False)