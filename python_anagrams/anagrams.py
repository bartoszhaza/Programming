# -*- coding: utf-8 -*-
"""
Created on Tue Nov 10 14:39:22 2015
****************************
*      Coursework 1        *
*  Programming for the Web *
*       COMP 1011          *
*   Author: Bartosz Haza   *
****************************
"""
#**********        
#* Part 1 *
#********** 
#First function, will compare the two strings str1 and str2.
def anagram(str1, str2):
    
    #If str1 isnt equal to str2 then it will return false. Otherwise it will be true.
    if len(str1) != len(str2):
        return False
        
#**********        
#* Part 2 *
#**********    
    #Second function, this will retrieve the value from the
    #first function into human readable text so true or false will be printed.
    def test_anagram(str):
        
        #Empty set variable
        test_anagram = []
        
        #for look n in str to check the similarities in the set's.
        for n in str:
            test_anagram[n] = test_anagram.get(n, 0) + 1
        #test_anagram will be returned so that when the program is run it will print the statmenets.
        return test_anagram
        
    #sorted sorts the two string variables into an alphabetical order.
    return sorted(str1) == sorted(str2)

#Test print statements will return either "True" or "False".
#Test 1: True
str1 = "bartek"
str2 = "tekbar"
print("The anagram \"bartek\" \"tekbar\" is",anagram(str1, str2))

#Test 2: False
str1 = "john"
str2 = "haza"
print("The anagram \"john\" \"haza\" is", anagram(str1, str2))

#Test 3: False
str1 = "jimmyboy"
str2 = "manytrees"
print("The anagram \"jimmyboy\" \"manytrees\" is",anagram(str1, str2))

#Test 4: True
str1 = "cake"
str2 = "keca"
print("The anagram \"cake\" \"keca\" is",anagram(str1, str2))

#**********        
#* Part 3 *
#**********
#This function will print out all of the words in the text file dictionary.
def get_dictionary_wordlist():
    
    #Empty set variable
    entry = []
    
    #This will open the file dictionary.txt.
    with open("dictionary.txt", "r") as fileObject:
        #While the statement is True so there is a line with text, it will be printed.
        while True:
            #Variable line defined to check the line.
            line = fileObject.readline()
            #The program is intended to break when it reaches and empty space.
            if line == "":
                    break
            else:
                #Will delete the new character so it will all print on the same line.
                entry.append(line[:-1])                       
    #Retur variable entry.            
    return entry
    
#**********        
#* Part 4 *
#**********
#This function will call the get_dictionary_wordlist
#and print out the first 10 words and how many words there
#are in the whole dictionary text file.
def test_dictionary_wordlist():
    
    #Entry will be assigned to the function get_dictionary_wordlist()
    entry = get_dictionary_wordlist()
    
    #The amount of words in the file will be printed.
    print("Number of words in the document: ", len(entry))
    
    #The first 10 words of the document will be printed.
    print("First 10 Words: ", entry[0:10])
    
#call the test_dictionary_wordlist so the output will be printed when the whole program is run.    
test_dictionary_wordlist()

#**********        
#* Part 5 *
#**********
#This function will print anagrams of a word when a list of words is given.
def find_anagrams_in_wordlist(str1, str_list):
    
    #Empty set variable.
    anagrams = []
    
    #Define a word in the str_list.
    for word in str_list:
        #If the word is equal to the string it will be added a the end of the word.
        if len(word) == len(str1):
            if (anagram(str1, word)):
                #Words equivalent added after str.
                anagrams.append(word)
            #Words that are the variables "str" annagrams will be printed.    
print(anagram("cake", "keca"))

#**********        
#* Part 6 *
#**********
#This will return all words in the dictionary that are anagrams of a
#word that has been inputted into the console.
def find_anagrams(str):
    
    #Return statement will return a word from the get_dictionary_wordlist.
    return [word for word in get_dictionary_wordlist() if anagram(word,str)]

#**********        
#* Part 7 *
#**********
#Function with no arguments will call the find_anagrams function.
def test_find_anagrams():
    
    #Test 1: Return actual anagrams.
    print("test_find_anagrams(1):(seabird):", find_anagrams("seabird"))
    
    #Test 2: Return actual anagrams.
    print("test_find_anagrams(2):(cheese):", find_anagrams("cheese"))
    
    #Test 3: Empty list.
    print("test_find_anagrams(3):(Bartek):", find_anagrams("Bartek"))
    
#This will run the test_find_anagrams function and will print it out when the program is run.
test_find_anagrams()
             
#**********        
#* Part 8 *
#**********
#I made a sub_anagram function that will find a smaller anagram of two words
#if a word is "bazaaaa" and the other one is "aaaatu" then it would
#output true.
def sub_anagram(str1, str2):
    
    #Parameter str1 assigned to a list.
    list1 = list(str1)
    #Parameter str2 assigned to a list.
    list2 = list(str2)
    #list1 sorted alphabetically.
    list.sort(list1)
    #list2 sorted alphabetically.
    list.sort(list2)    
    
    result = "True"
    
    #Loop for list2 condition.
    for letter in list2: 
        #if list2 is greater than list1 or letter is not in list1 it will return false.
        if list2.count(letter) > list1.count(letter) or letter not in list1:
            #result is False which breaks the loop.
            result = "False"
            break
    #The result varible will be returned as it holds the True value which should only be printed.
    return result
    return True
    
#**********        
#* Part 9 *
#**********
#Function with two arguments and return a list of words that are in the second argument
#if that sub_anagrams of the first argument.
def find_sub_anagram_in_wordlist(str, str_list):
    #Empty set variable.
    sub_anagrams = []
    
    #for loop if the value is true, so has a sub_anagram it will append the word from the sub_annagrams with the word.
    for word in str_list:
        #result condition, str and the word which is in str_list will be compared.
        result = sub_anagram(str, word)
        #if the result is true the word will append onto the end of str.
        if result == "True":
            #word added on the end of str.
            sub_anagrams.append(word)
    #sub_anagrams will be returned in order to compare the two.
    return sub_anagrams

#**********        
#* Part 10*
#**********
#Testing function to test the find_sub_anagram_in_wordlist.
def test_find_sub_anagram_in_wordlist():
    
    #Test 1: Return actual sub_anagram.    
    print("test_find_sub_anagram_in_wordlist(1):(dad)", find_sub_anagram_in_wordlist("dad", ["da", "ad", "dad"]))
    
    #Test 2: Return actual sub_anagram.
    print("test_find_sub_anagram_in_wordlist(2):(cheese)", find_sub_anagram_in_wordlist("cheese", ["che", "eese", "se", "ee"]))    
    
    #Test 3: Return actual sub_anagram.
    print("test_find_sub_anagram_in_wordlist(3):(wolf)", find_sub_anagram_in_wordlist("wolf", ["wol", "lf", "ol", "wf"]))
    
    #Test 4: Empty list.
    print("test_find_sub_anagram_in_wordlist(4):(joda)", find_sub_anagram_in_wordlist("joda", ["di", "bat", "vader"]))
    
#This will print out the print statements when the program is run, instead of running the function manually.
test_find_sub_anagram_in_wordlist()

#**********        
#* Part 11*
#**********
#Function to remove letters from str1 by the use of str2 and their similarities,
#if both have the same letters, them letters will
def remove_letters(str1, str2):
    
    #Store str1 in list1.
    list1 = list(str1)
    #Store str2 in list2.
    list2 = list(str2)
    
    #for when there is a letter in list1 that there is in list2 the list equation would be (list1 - list2).
    for letter in list2:
        if letter in list1:
            #This will remove list2 from list1.
            list1.remove(letter)      
    #list1 after being changed will be returned.
    return ''.join(list1) 

#**********        
#* Part 12*
#**********
#Function that will call the remove_letters function and print out the different inputs.
def test_remove_letters():
    
    #Test 1: str2 contains letters not in str1.
    print("test_remove_letters(1):", remove_letters("bartek", "bart"))
    
    #Test 2: str1 = str2.
    print("test_remove_letters(2):", remove_letters("nathaniel", "nathaniel"))
    
    #Test 3: str2 is empty.
    print("test_remove_letters(3):", remove_letters("danny", ""))
    
    #Test 4: str1 is empty.
    print("test_remove_letters(4):", remove_letters("", "lewis"))
    
    #Test 5: str2 contains all letters in str1.
    print("test_remove_letters(5):", remove_letters("seabird", "sidebar"))
    
    #Test 6: Both strings are empty.
    print("test_remove_letters(6):", remove_letters("", ""))

#This will print the function test_remove_letters when the program is run.    
test_remove_letters()

    
    