module newton

    ! module parameters:
    implicit none
    integer, parameter :: maxiter = 100
    real(kind=8), parameter :: tol = 1.d-14

contains

subroutine root_newton(f, fp, x0, x, iters, debug)

    ! Estimate the zero of f(x) using Newton's method. 
    ! Input:
    !   f:  the function to find a root of
    !   fp: function returning the derivative f'
    !   x0: the initial guess
    !   debug: logical, prints iterations if debug=.true.
    ! Returns:
    !   the estimate x satisfying f(x)=0 (assumes Newton converged!) 
    !   the number of iterations iters
     
    implicit none
    real(kind=8), intent(in) :: x0
    real(kind=8), external :: f, fp
    logical, intent(in) :: debug
    real(kind=8), intent(out) :: x
    integer, intent(out) :: iters

    ! Declare any local variables:
    real(kind=8) :: deltax, fx, fxprime
    integer :: k

    ! initial guess
    x = x0

    if (debug) then
        print 11, x
 11     format('Initial guess: x = ', e22.15)
    endif

    ! Newton iteration to find a zero of f(x) 

    do k=1,maxiter

        ! evaluate function and its derivative:
        fx = f(x)
        fxprime = fp(x)

        if (abs(fx) < tol) then
            exit  ! jump out of do loop
            endif

        ! compute Newton increment x:
        deltax = fx/fxprime

        ! update x:
        x = x - deltax

        if (debug) then
            print 12, k,x
 12         format('After', i3, ' iterations, x = ', e22.15)
            endif

        enddo


    if (k > maxiter) then
        ! might not have converged

        fx = f(x)
        if (abs(fx) > tol) then
            print *, '*** Warning: has not yet converged'
            endif
        endif 

    ! number of iterations taken:
    iters = k-1

end subroutine root_newton

end module newton

module functions

contains

real(kind=8) function f_sqrt(x)
    implicit none
    real(kind=8), intent(in) :: x

    f_sqrt = x**2 - 4.d0

end function f_sqrt


real(kind=8) function fprime_sqrt(x)
    implicit none
    real(kind=8), intent(in) :: x

    fprime_sqrt = 2.d0 * x

end function fprime_sqrt

end module functions


program test_newton

    use newton, only: root_newton
    use functions, only: f_sqrt, fprime_sqrt

    implicit none
    real(kind=8) :: x, x0, fx
    real(kind=8) :: x0vals(3)
    integer :: iters, itest
	logical :: debug         ! set to .true. or .false.

    print *, "Test routine for computing zero of f"
    debug = .true.

    ! values to test as x0:
    x0vals = (/1.d0, 2.d0, 100.d0 /)

    do itest=1,3
        x0 = x0vals(itest)
        print *, ' '  ! blank line
        call root_newton(f_sqrt, fprime_sqrt, x0, x, iters, debug)

        print 11, x, iters
11      format('solver returns x = ', e22.15, ' after', i3, ' iterations')

        fx = f_sqrt(x)
        print 12, fx
12      format('the value of f(x) is ', e22.15)

        if (abs(x-2.d0) > 1d-14) then
            print 13, x
13          format('*** Unexpected result: x = ', e22.15)
            endif
        enddo

end program test_newton
