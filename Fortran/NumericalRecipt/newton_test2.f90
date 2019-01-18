module newton

    ! module parameters:
    implicit none
    real(kind=8), parameter :: tol = 1.d-9

contains

subroutine root_newton(f, fp, x0, x, farg1, maxiter_in, debug_in)

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
    real(kind=8), intent(in) :: x0, farg1
    real(kind=8), external :: f, fp
    real(kind=8), intent(out) :: x
    integer, intent(in), optional :: maxiter_in
    logical, intent(in), optional :: debug_in

    ! Declare any local variables:
    integer :: maxiter, iters
    logical :: debug
    real(kind=8) :: deltax, fx, fxprime
    integer :: k

    ! defualt 
    maxiter = 100
    debug = .false.

    ! optional
    if (present(maxiter_in)) maxiter = maxiter_in
    if (present(debug_in)) debug = debug_in

    ! initial guess
    x = x0

    if (debug) then
        write(*,*) 'Initial guess: x = ', x
    endif

    ! Newton iteration to find a zero of f(x) 
    fx = f(x, farg1)
    iters = 0
    do while (DABS(fx) >= tol)
        iters = iters+1
        ! evaluate function and its derivative:
        fx = f(x,farg1)
        fxprime = fp(x,farg1)

        ! compute Newton increment x:
        deltax = fx/fxprime

        ! update x:
        x = x - deltax

        if (debug) then
            write(12,*) k,x
 12         format('After', i3, ' iterations, x = ', e22.15)
        endif
        if (iters > maxiter) then
            write(*,*) 'not coonverged within the maxiter=', iters
            write(*,*) 'the difference is ',fx
            exit
        endif
    enddo

end subroutine root_newton

end module newton

module functions

contains

real(kind=8) function f_sqrt(x, farg1)
    implicit none
    real(kind=8), intent(in) :: x, farg1

    f_sqrt = x**2 - farg1

end function f_sqrt


real(kind=8) function fprime_sqrt(x, farg1)
    implicit none
    real(kind=8), intent(in) :: x, farg1

    fprime_sqrt = 2.d0 * x

end function fprime_sqrt

end module functions


program newton_test2

    use newton, only: root_newton
    use functions, only: f_sqrt, fprime_sqrt

    implicit none
    real(kind=8) :: x, x0
    logical :: debug         ! set to .true. or .false.

    print *, "Test routine for computing zero of f"
    debug = .false.

    ! values to test as x0:
    x0 = 2.

    call root_newton(f_sqrt, fprime_sqrt, x0, x, 81.D0, debug_in=debug)
    write(*,*)'computed value of x is ', x

    
end program newton_test2
