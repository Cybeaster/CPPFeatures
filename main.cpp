
struct base
{
   base() = delete;
   base(const base& Base) = delete;

   base operator()() = delete;

   void operator=(const base& Base) = delete;

   int fd;
};

void main()
{
   base (*_Base)();
   
}