
# Assuming @sheet is your two-dimensional array
@sheet = (
    ['row1col1', 'row1col2', 'row1col3'],
    ['row2col1', 'row2col2', 'row2col3'],
    ['row3col1', 'row3col2', 'row3col3'],
);

foreach my $row_ref (@sheet) {
    # $row_ref is a reference to each row array
    foreach my $cell (@{$row_ref}) {
        # $cell is each element (cell) in the row
        print "$cell ";
    }
    print "\n"; # Print a newline at the end of each row
}

my @original_array = (1, 2, 3);
my $array_ref = \@original_array; # Get a reference to @original_array

# Dereference $array_ref to access @original_array and print its elements
foreach my $element (@{$array_ref}) {
    print "$element\n";
}

# Accessing a specific element
my $element = $sheet[$row_index][$column_index];

foreach my $row_ref (@sheet) {
    # Iterate through each column of the current row
    for (my $i = 0; $i < @{$row_ref}; $i++) {
        # Access each element using square brackets
        print $row_ref->[$i] . " ";
    }
    print "\n"; # New line at the end of each row
}

my $row_index = 1; # Remember, array indices start at 0
my $column_index = 2; # Third column, index starts at 0

my $element = $sheet[$row_index][$column_index];
print "$element\n"; # Prints: row2col3

# Let's say we're iterating over each row
foreach my $row_ref (@sheet) {
    # Now, accessing specific elements in the row
    my $third_element = $row_ref->[2]; # Access the 3rd element
    my $fourth_element = $row_ref->[3]; # Access the 4th element
    
    print "Third element: $third_element, Fourth element: $fourth_element\n";
}

# Perl References
# Created by prefixing a variable with a backslash (\).
#   Accessed or manipulated using the dereference operator (->), or 
#   by using the appropriate type symbol (@{}, %{}, *{}) for arrays, hashes, 
#   and typeglobs, respectively.
#   Used to create complex data structures like arrays of arrays, 
#   hashes of arrays, etc.
#   Syntax for dereferencing is slightly higher-level compared to C,
#   with built-in support for complex data structures.
# C Pointers
#   Created by declaring a variable with an asterisk (*) to denote it 
#   as a pointer.
#   Accessed or manipulated using the dereference operator (*) to access 
#   the value pointed to, or the address-of operator (&) to get the 
#   address of a variable.
#   Used for dynamic memory allocation, array manipulation, 
#   function pointers, and more.
#   Requires manual management of memory allocation and 
#   deallocation (e.g., using malloc and free).
