def selection_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

def display_top_scores(arr, top_n=5):
    print("Top", top_n, "Scores:")
    for i in range(min(top_n, len(arr))):
        print(arr[i])

# Main program
if __name__ == "__main__":
    percentages = []

    while True:
        print("\n1. Enter student percentages")
        print("2. Selection Sort and display top scores")
        print("3. Bubble Sort and display top scores")
        print("4. Exit")

        choice = input("Enter your choice (1-4): ")

        if choice == "1":
            n = int(input("Enter the number of students: "))
            percentages = []
            for i in range(n):
                percentage = float(input(f"Enter the percentage for student {i + 1}: "))
                percentages.append(percentage)
        elif choice == "2":
            if not percentages:
                print("Please enter student percentages first.")
            else:
                selection_sort_array = percentages.copy()
                selection_sort(selection_sort_array)
                print("\nAfter Selection Sort:")
                display_top_scores(selection_sort_array)
        elif choice == "3":
            if not percentages:
                print("Please enter student percentages first.")
            else:
                bubble_sort_array = percentages.copy()
                bubble_sort(bubble_sort_array)
                print("\nAfter Bubble Sort:")
                display_top_scores(bubble_sort_array)
        elif choice == "4":
            print("Exiting the program.")
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 4.")
