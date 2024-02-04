import random

quantity_of_numbers = 3000
start_number = 1.0
end_number = 10.0  # Define the upper limit for the random floats
step = (end_number - start_number) / quantity_of_numbers  # Calculate step to generate unique floats

# Generate a list of unique floating-point numbers
numbers = [start_number + i * step for i in range(quantity_of_numbers)]

# Shuffle the list to randomize the order of numbers
random.shuffle(numbers)

# Convert the list of numbers into a string formatted like a C array of floats
c_array_str = "float arr[] = {" + ", ".join(f"{num:.2f}" for num in numbers) + "};"

# Specify the filename
filename = f"binary_search_quicksort_float_{quantity_of_numbers}_floats.txt"

# Write the string to a file
with open(filename, 'w') as file:
    file.write(c_array_str)

print(f"Array saved to {filename}")
