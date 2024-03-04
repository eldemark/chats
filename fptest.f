c     Fortran 77

      program TestFloatingPoint
      double precision a, b, c, d, e
      double precision result1, result2, result3, result4, result5

c     Initialize variables
      a = 1.23456789
      b = 9.87654321
      c = 2.34567890
      d = 8.76543210
      e = 3.45678901

c     Perform operations
      result1 = a + b - c * d / e
      result2 = d ** 2
      result3 = sqrt(a)
      result4 = a / b + exp(c) - log(d)
      result5 = sin(a) + cos(b) * tan(c)

c     Print results
      print *, 'Result of operation 1:', result1
      print *, 'Result of operation 2:', result2
      print *, 'Result of square root of a:', result3
      print *, 'Result of operation 4:', result4
      print *, 'Result of operation 5:', result5

      end
