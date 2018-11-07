# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <ctime>
# include <string>
# include <sstream>
using namespace std;

# include "mpi.h"

int main ( int argc, char *argv[] );


int main ( int argc, char *argv[] )
{
  int id;
  int p;
  double wtime;
  MPI::Init ( argc, argv );
  p = MPI::COMM_WORLD.Get_size ( );
  id = MPI::COMM_WORLD.Get_rank ( );
  if ( id == 0 )
  {
    wtime = MPI::Wtime ( );
  }

    string command = "java MPISMBIONET ";
    command.append(argv[1]);
    command.append(" ");
    std::ostringstream convert;
    convert<< id;
    command.append(convert.str());
    command.append(" ");
    convert.str("");
    convert<< p;
    command.append(convert.str());
//    cout<<endl<<command;
    const char* exec = command.c_str();
    system(exec);

  MPI::COMM_WORLD.Barrier();
  if ( id == 0 )
  {
    wtime = MPI::Wtime ( ) - wtime;
    cout << "  Elapsed wall clock time = " << wtime << " seconds.\n";
  }
  MPI::Finalize ( );
  if ( id == 0 )
  {
    cout << "\n";
    cout << "SMBIONET_CLUSTER:\n";
    cout << "  Normal end of execution.\n";
    cout << "\n";
  }
  return 0;
}

