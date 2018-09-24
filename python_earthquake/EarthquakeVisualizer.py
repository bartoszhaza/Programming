# -*- coding: utf-8 -*-
"""
Created on Tue Nov 24 13:45:06 2015

@author: BartoszHaza
"""

import csv #the csv file will be imported

################
#Basic Solution#
################

########
#Part 1#
########

def earthquake_data(): #first function to read the csv file
    empty_earthquake_data = [] #empty list
    with open('earthquakedata.csv', 'r') as file: #statement to open csv file and assign it to file
        reader = csv.reader(file) #reader will be assigned to the file
        next(file) #next will skip the header so it won't be printed
        for row in reader: #for statement, for every for in reader which is now the csv file
            empty_earthquake_data.append(row) #the variable string will be appended by row
    return empty_earthquake_data #this will return the variable


########
#Part 2#
########

def organised_earthquake_data(): #second function that will print an organised dataset with, time, latitude, longitude, depth and magnitude  
    with open('earthquakedata.csv', 'r') as file:
        reader = csv.reader(file, delimiter=',')
        next(reader)
        for row in reader:
            for item in row:
                print(row[0:5])
        return row

########
#Part 3#
########

def writeHTML():
	with open("filename.html","w") as html:
		html.write("<!DOCTYPE html>\n")
		html.write("<html>\n")
		html.write("<head>\n")
		html.write("<meta charset=\"UTF-8\">\n")
		html.write("<style>\n")
		html.write("table, th, td {\n")
		html.write("border: 1px solid black;\n")
		html.write("border-collapse: collapse;\n")
		html.write("}\n")
		html.write("</style>\n")
		html.write("<title>Title of the document</title>\n")
		html.write("</head>\n")
		html.write("<body>\n")
		html.write("<h2>Header title</h2>\n")
		html.write("<table>\n")
		import csv
		with open("earthquakedata.csv","r") as csv_table:
			csv_table.readline()
			html.write("<tr>\n")
			html.write("<th>time</th>\n")	
			html.write("<th>latitude</th>\n")
			html.write("<th>longitude</th>\n")
			html.write("<th>depth</th>\n")
			html.write("<th>mag</th>\n")
			html.write("<th>magType<t/th>\n")
			html.write("<th>nst<t/th>\n")
			html.write("<th>gap<t/th>\n")
			html.write("<th>dmin<t/th>\n")
			html.write("<th>rms<t/th>\n")
			html.write("<th>net<t/th>\n")
			html.write("<th>id<t/th>\n")
			html.write("<th>updated<t/th>\n")
			html.write("<th>place<t/th>\n")
			html.write("<th>type<t/th>\n")
			html.write("</tr>\n")
		
			reader = csv.reader(csv_table)
			for row in reader:
				html.write("</tr>\n")
				for element in row:
					html.write("<td>\n" + element + "</td>\n")
				html.write("</tr>\n")
		
		html.write("</table>\n")
		html.write("</body>\n")
		html.write("</html>\n")   
  
#######################
#Intermediate Solution#
#######################

#########
#Part 1a#
#########

def numberOfQuakes(): #first function to count the amount of earthquakes 
    with open('earthquakedata.csv', 'r') as file: #the file will be opened as 'file'
        content = file.read() #content is list assigned to file.read()
    return content.count("earthquake") #the content.count("earthquake") will return the amount of earthquakes 
numberOfQuakes() #this will call the function so it prints

#########
#Part 1b#
#########

def averageDepth(): #average of depth function
    with open('earthquakedata.csv', 'r') as file: #open csv as read file and assign it to file
        reader = csv.DictReader(file) #reader contains the csv file that was assigned to file
        i = [] #empty listy
        for row in reader: #for loop to scan through the reader which is the csv file
            try:
                j = float(row['depth']) #j is the row this will be the number of numbers in the column "depth"
                i.append(j) #i appended by j
            except ValueError:
                print() #nothing to print
    average = sum(i) / len(i) #average formula
    return average #the formula average will be returned

#########
#Part 1c#
#########

def maxMag(): #maximum magnitude function
    with open('earthquakedata.csv', 'r') as file: #open csv as read file and assign it to file
        reader = csv.DictReader(file) #reader contains the csv file that was assigned to file
        i = [] #empty listy
        for row in reader: #for loop to scan through the reader which is the csv file
            try:
                j = float(row['mag']) #j is the row this will be the number of numbers in the column "depth"
                i.append(j) #i appended by j
            except ValueError:
                print() #nothing to print
    max_Mag = max(i) #maximum formula
    return max_Mag #the formula maximum will be returned

#########
#Part 1d#
#########

def minMag(): #minimum magnitude function
    with open('earthquakedata.csv', 'r') as file: #open csv as read file and assign it to file
        reader = csv.DictReader(file) #reader contains the csv file that was assigned to file
        i = [] #empty listy
        for row in reader: #for loop to scan through the reader which is the csv file
            try:
                j = float(row['mag']) #j is the row this will be the number of numbers in the column "depth"
                i.append(j) #i appended by j
            except ValueError:
                print() #nothing to print
    min_Mag = min(i) #minimum formula
    return min_Mag #the formula minumum will be returned

########
#Part 2#
########

def new_writeHTML(): #new html file function
	with open("filename.html","w") as html: #this will open the file as "html" so if anything needs to be done with it hte "html" shortcut will be used
		html.write("<!DOCTYPE html>\n")
		html.write("<html>\n")
		html.write("<head>\n")
		html.write("<meta charset=\"UTF-8\">\n")
		html.write("<style>\n")
		html.write("table, th, td {\n")
		html.write("border: 1px solid black;\n")
		html.write("border-collapse: collapse;\n")
		html.write("}\n")
		html.write("</style>\n")
		html.write("<title>Title of the document</title>\n")
		html.write("</head>\n")
		html.write("<body>\n")
		html.write("<h2>Number of Quakes: 7736</h2>\n") #number of quakes
		html.write("<h2>Average Depth = 25.307772837150186</h2>\n") #average depth
		html.write("<h2>Max magnitude: 7.8</h2>\n") #max magnitude
		html.write("<h2>Min magnitude: -0.73</h2>\n") #min magnitude
		html.write("<table>\n")
		import csv # csv will be imported here
		with open("earthquakedata.csv","r") as csv_table: #will open the csv as csv_table
			csv_table.readline()
			html.write("<tr>\n")
			html.write("<th>time</th>\n")	
			html.write("<th>latitude</th>\n")
			html.write("<th>longitude</th>\n")
			html.write("<th>depth</th>\n")
			html.write("<th>mag</th>\n")
			html.write("<th>magType<t/th>\n")
			html.write("<th>nst<t/th>\n")
			html.write("<th>gap<t/th>\n")
			html.write("<th>dmin<t/th>\n")
			html.write("<th>rms<t/th>\n")
			html.write("<th>net<t/th>\n")
			html.write("<th>id<t/th>\n")
			html.write("<th>updated<t/th>\n")
			html.write("<th>place<t/th>\n")
			html.write("<th>type<t/th>\n")
			html.write("</tr>\n")
		
			reader = csv.reader(csv_table) #reads the file then assigned to csv_table
			for row in reader: #for each row in the reader do the following
				html.write("</tr>\n") #print a table
				for element in row: #for element int row dow the following
					html.write("<td>\n" + element + "</td>\n") #print table
				html.write("</tr>\n") #print table

		html.write("</table>\n")
		html.write("</body>\n")
		html.write("</html>\n")

########
#Part 3#
########

#custom menu table that will hold the options on what to enter
print(40 * '*') #amount of symbols printed
print("              MAIN MENU") #main text
print(40 * '*') #symbol split
print("1. View earthquake data") #first option
print("2. View statistics") #second option
print("3. Create html") #third option
print("4. Overwrite the current html") #fourth option
print("5. Latest database") #fith option
print("6. Exit") #sixth option
print(40 * '*') #symbol split

choice = input("Enter option [1-6]: ") #prompt input range

choice = int(choice) #choice number

if choice == 1: #first choice
    print("Entering earthquake data...")
    print("Earthquake Data: ", earthquake_data()) #will print earthquake_data
    
elif choice == 2: #second choice
    print("Entering statistics...")
    print("Max magnitude: ", maxMag()) #prints max magnitude
    print("Min magnitude: ", minMag()) #prints min magnitude
    print("Average depth: ", averageDepth()) #average depth
    print("Number of earthquakes: ", numberOfQuakes()) #number of quakes will be printed
    
elif choice == 3: #third choice
    print("Entering create html...") 
    print("Created HTML: ", writeHTML()) #this will write a new html file
    
elif choice == 4: #fourth choice
    print("Overwriting existing html...")
    print("New HTML has been overwritten: ", new_writeHTML()) #this will overwrite the previous html file with the functions on

elif choice == 5: #fith choice
    print("Opening latest database...")
    print("Latest database has been opened: ", new_writeHTML()) #prints the latest database
    
elif choice == 6: #sixth choice
    print("Bye bye") #bye bye, prompt if choice 6 is chosen 
    
else: #if one of the choices is not picked it will do this
    print("Invalid value, enter an option between [1-6]") #invalid out of range value will print
    
###################
#Advanced Solution#
###################

########
#Part 1#
########

import urllib.request #lirary

def readDataFromURL(): #function to read the html
	try: #try to do 
		lines = [] #empty list
		url = 'http://earthquake.usgs.gov/earthquakes/feed/v1.0/summary/all_month.csv' #specified url
		response = urllib.request.urlopen(url)
		reader = csv.reader(response.read().decode('utf-8').splitlines()) #read the file
		
		for row in reader: #for each row in reader (the csv file)
				lines.append(row) #append list "lines" by row
		return lines #return the list "lines"
	except (Exception): #if it's not successful
		print("Unable to get data from website") #print when unsuccessful

