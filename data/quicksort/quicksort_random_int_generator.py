import random

quantity_of_numbers = 100000;
start_number = 1;
end_number = quantity_of_numbers + start_number;

# Generate a list of a million unique numbers
numbers = list(range(start_number, quantity_of_numbers + start_number))

# Shuffle the list to randomize the order of numbers
random.shuffle(numbers)

# Convert the list of numbers into a string formatted like a C array
c_array_str = f"int arr[] = {{{', '.join(map(str, numbers))}}};"

# Specify the filename
filename = f"quicksort_array_{quantity_of_numbers}.txt"

# Write the string to a file
with open(filename, 'w') as file:
    file.write(c_array_str)

print(f"Array saved to {filename}")
