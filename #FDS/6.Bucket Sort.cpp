def bucket_sort(arr):
    n = len(arr)
    buckets = [[] for _ in range(n)]

    for num in arr:
        index = int(num * n)
        buckets[index].append(num)

    for bucket in buckets:
        bucket.sort()

    sorted_array = [num for bucket in buckets for num in bucket]
    return sorted_array

def display_top_scores(arr, top_n=5):
    print("Top", top_n, "Scores:")
    for i in range(min(top_n, len(arr))):
        print(arr[i])

# Main program
percentages = []

while True:
    print("\n1. Enter student marks")
    print("2. Bucket Sort and display top scores")
    print("3. Exit")

    choice = input("Enter your choice (1-3): ")

    if choice == "1":
        n = int(input("Enter the number of students: "))
        percentages = []
        for i in range(n):
            percentage = float(input(f"Enter the percentage for student {i + 1}: "))
            percentages.append(percentage / 100.0)  # Convert to a decimal between 0 and 1
    elif choice == "2":
        if not percentages:
            print("Please enter student percentages first.")
        else:
            sorted_percentages = bucket_sort(percentages)
            print("\nAfter Bucket Sort:")
            display_top_scores(sorted_percentages, top_n=5)
    elif choice == "3":
        print("Exiting the program.")
        break
    else:
        print("Invalid choice. Please enter a number between 1 and 3.")
