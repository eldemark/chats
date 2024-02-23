use strict;
use warnings;
use Text::CSV;

# Define the input and output CSV file paths
my $input_file = 'input.csv';
my $output_file = 'output.csv';

# Open the input file
open my $in_fh, '<', $input_file or die "Could not open '$input_file' $!";

# Create a Text::CSV object for reading
my $csv = Text::CSV->new({ binary => 1, auto_diag => 1 });

# Open the output file
open my $out_fh, '>', $output_file or die "Could not open '$output_file' $!";

# Read the header row and add new column names
if (my $row = $csv->getline($in_fh)) {
    push @$row, 'NewColumn1', 'NewColumn2'; # Add new column names here
    $csv->say($out_fh, $row);
}

# Process each row
while (my $row = $csv->getline($in_fh)) {
    # Assume we're adding new columns based on the first two existing columns
    my $new_value1 = $row->[0] * 2; # Example transformation for new column 1
    my $new_value2 = $row->[1] + 10; # Example transformation for new column 2

    # Append the new values to the row
    push @$row, $new_value1, $new_value2;

    # Write the modified row to the output file
    $csv->say($out_fh, $row);
}

# Close filehandles
close $in_fh;
close $out_fh;

print "Processing complete. New data written to '$output_file'.\n";

# push @array, $value1, $value2, ..., $valueN;

my @fruits = ('apple', 'banana');
push @fruits, 'orange', 'grape', 'mango';

