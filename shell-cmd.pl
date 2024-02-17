
# idiomatic use of back ticks
my $output = `ls`;
print $output;


# Checking return status with special variable: $?
`mv $foo $bar`;
if ($? == -1) {
    print "failed to execute: $!\n";
} elsif ($? & 127) {
    printf "child died with signal %d, %s coredump\n",
        ($? & 127),  ($? & 128) ? 'with' : 'without';
} else {
    printf "child exited with value %d\n", $? >> 8;
}

# Parens equivalent.
printf("Hello, %s!\n", $name);
printf "Hello, %s!\n", $name;

# => prefered
my %hash = ('key1', 'value1', 'key2', 'value2');
my %hash = (key1 => 'value1', key2 => 'value2');

# Single vs double quotes
my $name = 'World';
print 'Hello, $name\n'; # Outputs: Hello, $name\n
my $name = 'World';
print "Hello, $name\n"; # Outputs: Hello, World (with a newline at the end)

# Array of floats
my @floats = (1.1, 2.2, 3.3, 4.4, 5.5);
foreach my $float (@floats) {
    print "$float\n";
}

#!/usr/bin/perl
use strict;
use warnings;

# Declare an array of floating-point numbers
my @floats = (1.1, 2.2, 3.3, 4.4, 5.5);

# Iterate over the array and print each floating-point number
foreach my $float (@floats) {
    print "$float\n";
}

# Numeric command line args

#!/usr/bin/perl
use strict;
use warnings;

# Check if at least two arguments were provided
if (@ARGV < 2) {
    die "Usage: $0 number1 number2\n";
}

# Assign command-line arguments to variables
my $num1 = $ARGV[0];
my $num2 = $ARGV[1];

# Optionally, convert them to numbers explicitly
# This step is implicit if you use them in a numeric context
$num1 += 0;
$num2 += 0;

# Use the numbers in your application
print "First number: $num1\n";
print "Second number: $num2\n";

# Example calculation
my $sum = $num1 + $num2;
print "Sum: $sum\n";

# Numeric vs string context
#!/usr/bin/perl
use strict;
use warnings;

my $num1 = $ARGV[0]; # Command line arguments are initially strings
my $num2 = $ARGV[1];

my $sum = $num1 + $num2; # Numeric context: strings are converted to numbers
print "Sum: $sum\n";

