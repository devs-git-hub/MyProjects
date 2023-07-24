import os

def read_diary():
    # Function to read and display the contents of the diary file
    diary_file = "diary.txt"
    if os.path.exists(diary_file):
        with open(diary_file, "r") as file:
            contents = file.read()
            print(contents)
    else:
        print("Diary file not found. Start writing your first entry!")

def write_diary():
    # Function to write a new entry in the diary
    diary_file = "diary.txt"
    entry = input("Write your diary entry:\n")
    with open(diary_file, "a") as file:
        file.write(entry + "\n")
    print("Entry saved successfully!")

def search_diary():
    # Function to search for specific text in the diary
    diary_file = "diary.txt"
    search_text = input("Enter the text to search for:\n")
    with open(diary_file, "r") as file:
        for line in file:
            if search_text in line:
                print(line.strip())

def delete_diary():
    # Function to delete the entire diary file
    diary_file = "diary.txt"
    if os.path.exists(diary_file):
        os.remove(diary_file)
        print("Diary file deleted successfully!")
    else:
        print("Diary file not found.")

def show_menu():
    # Function to display the menu options
    print("\nPersonal Diary Management System")
    print("1. Read Diary")
    print("2. Write Diary")
    print("3. Search Diary")
    print("4. Delete Diary")
    print("5. Exit")

# Main loop
while True:
    show_menu()
    choice = input("Enter your choice (1-5): ")

    if choice == "1":
        read_diary()
    elif choice == "2":
        write_diary()
    elif choice == "3":
        search_diary()
    elif choice == "4":
        delete_diary()
    elif choice == "5":
        print("Exiting...")
        break
    else:
        print("Invalid choice. Please try again.")
