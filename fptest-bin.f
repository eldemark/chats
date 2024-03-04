      program TestFloatingPoint
      double precision a, b, c, d, e
      double precision result1, result2, result3, result4, result5
      integer unit

      unit = 10 ! Arbitrary file unit number

c     Initialize variables with more digits of precision
      a = 1.23456789012345
      b = 9.87654321098765
      c = 2.34567890123456
      d = 8.76543210987654
      e = 3.45678901234567

c     Perform operations
      result1 = a + b - c * d / e
      result2 = d ** 2
      result3 = sqrt(a)
      result4 = a / b + exp(c) - log(d)
      result5 = sin(a) + cos(b) * tan(c)

c     Open binary file for output
      open(unit=unit, file='results.bin', status='unknown', form='unformatted')

c     Write results to binary file
      write(unit) result1
      write(unit) result2
      write(unit) result3
      write(unit) result4
      write(unit) result5

c     Close file
      close(unit)

      end

