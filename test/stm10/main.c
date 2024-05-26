int main ( void )
{
		// see disassembly
	int a = 2;
	int b = 3;
	int c = 0;

	_Bool result = 0;

	// equality
	result = a == a;
	result = !( a != b );

	// inequality
	result = a != b;
	result = !( a == b );

	// logical and
	result = ( a > b ) && ( b > c );

	// logical inclusive or
	result = ( a > b ) || ( b > c );

	// logical exclusive or (equivalent)
	result = ( a > b ) != ( b > c );

	// bool normalized exclusive or (equivalent)
	result = !a != !c;
	result = (_Bool)a != (_Bool)c;

	result = a >= b;
	result = !( a < b );

	result = a < b;
	result = !( a >= b );

	result = a <= b;
	result = !( a > b );

	return 0;
}