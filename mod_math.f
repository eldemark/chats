c Fortran Example
c module_math.f90:

module module_math
  implicit none
  contains
  subroutine add(a, b, result)
    real, intent(in) :: a, b
    real, intent(out) :: result
    result = a + b
  end subroutine add

  subroutine subtract(a, b, result)
    real, intent(in) :: a, b
    real, intent(out) :: result
    result = a - b
  end subroutine subtract
end module module_math

c main_program.f90:

program main
  use module_math
  implicit none
  real :: x, y, sum, difference

  x = 5.0
  y = 3.0

  call add(x, y, sum)
  call subtract(x, y, difference)

  print *, 'Sum:', sum
  print *, 'Difference:', difference
end program main

c In this example, use module_math includes the subroutines 
c add and subtract from the module_math module. 
c This approach ensures that the subroutines have 
c explicit interfaces, which helps with type 
c checking and argument matching.

