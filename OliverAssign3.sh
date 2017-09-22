#!/bin/bash

# Eric Oliver

# varaible to store contacts.dat
file="contacts.dat"

# Function to initilize the file
Init()
{

	clear

	if [ ! -f $file ]; then

		touch $file
		echo "Created contacts.dat"

	else

		echo "contact.dat exists!"

	fi

	echo "Eric Oliver's E-mail sorter"

}

# Function to display the menu
Menu() 
{

	echo ""
	echo "1. Add a contact"
	echo "2. Remove a contact"
	echo "3. Find a contact"
	echo "4. List all contacts"
	echo "5. Exit the pogram"

	read -p "Please enter your choice: " choice


	# Conditional statements to move through the menu
	if [ $choice -eq 1 ]; then
		Add

	elif [ $choice -eq 2 ]; then
		Remove

	elif [ $choice -eq 3 ]; then
		Find

	elif [ $choice -eq 4 ]; then
		List

	elif [ $choice -eq 5 ]; then
		echo "Thank you! Come again!"
		exit

	else
		echo "Please enter a valid choice"
		Menu

	fi

}

# Function to add a contact
Add()
{

	echo ""
	echo "Adding a Contact"
	echo
	read -p "Please enter a full name: " name
	read -p "Please enter an e-mail address: " email

	echo "$name $email" >> $file

	Menu

}

# Function to call the Search function to remove a contact
Remove()
{

	Search R

}

#Function to call the search function to find a contact
Find()
{

	Search F

}

#Function to list the contacts in sorted order
List()
{

	echo ""

	if [ -s $file ]; then

		echo "Sorted contacts list :"
		sort $file

	else

		echo "Contacts.dat is empty"

	fi

	Menu

}

#function to search through the file
Search()
{

	if [ $1 = "F" ]; then

		echo ""
		echo "Contact finder"
		echo ""
		read -p "Please enter a name: " name

		if grep -q $name $file; then

			grep $name $file

			Menu

		else

			echo "No one found"

			Menu

		fi

	elif [ $1 = "R" ]; then

		echo ""
		echo "Contact remover"
		echo ""
		read -p "Please enter a name: " name

		if grep -q $name $file; then

			echo "$name removed"

			sed -i /"$name"/d $file			

			Menu


		else

			echo "No one found"

			Menu

		fi

	fi

}

#main funciton calls
Init
Menu
