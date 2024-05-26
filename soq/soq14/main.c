#define ENTRY(entry) DEFINE(pda_ ## entry, offsetof(struct x8664_pda, entry))
#define DEFINE(sym, val) \
        asm volatile("\n->" #sym " %0 " #val : : "i" (val))

int main ( void )
{
    ENTRY( pcurrent );

    return 0;
}