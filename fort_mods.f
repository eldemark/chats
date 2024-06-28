c 1. Create the Interface Module
c Create a module file that contains the interfaces for all subroutines.
c interfaces.f90:

module interfaces
  implicit none
  ! Declare subroutine interfaces
  interface
    subroutine read_print_params
      implicit none
      ! Declare any common variables if needed
      integer i
      integer j
      common /foo/ param01, param02, param03
      real(4) :: param01
      real(4) :: param02
      real(4) :: param03
    end subroutine read_print_params
    ! Add more subroutine interfaces as needed
  end interface
end module interfaces

c 2. Create the Subroutine Definitions
c Each subroutine can be defined in its own file or within the same file.
c read_print_parameters.f90:

module read_print_params_mod
  use interfaces
  implicit none
  contains
  subroutine read_print_params
    integer i
    integer j
    common /foo/ param01, param02, param03
    real(4) :: param01
    real(4) :: param02
    real(4) :: param03
    ! Subroutine code goes here
    return
  end subroutine read_print_params
end module read_print_params_mod

c 3. Use the Module in Your Main Program
c Include the module in any program that calls the subroutines.
c main_program.f90:

program main
  use interfaces
  implicit none

  ! Common block variables
  common /foo/ param01, param02, param03
  real(4) :: param01
  real(4) :: param02
  real(4) :: param03

  ! Initialize parameters
  param01 = 1.0
  param02 = 2.0
  param03 = 3.0

  ! Call the subroutine
  call read_print_params

  ! Print the parameters
  print *, 'param01:', param01
  print *, 'param02:', param02
  print *, 'param03:', param03

end program main
