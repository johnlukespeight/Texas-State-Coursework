#include<iostream>
#include<fstream>  // need this for file I/O
#include<cstdlib>   // for exit()


using namespace std;

const int MAX_SIZE = 1000;

class Entry {
public:
  Entry();
  ~Entry();
  void display(ofstream& outfile);

  void set_tag(int _tag) { tag = _tag; }
  int get_tag() { return tag; }

  void set_valid(bool _valid) { valid = _valid; }
  bool get_valid() { return valid; }

  void set_ref(int _ref) { ref = _ref; }
  int get_ref() { return ref; }

private:
  bool valid;
  unsigned tag;
  int ref;
};

class Cache {
public:
  Cache(int, int);

  ~Cache();

  void display(ofstream& outfile)  {cout << entries[0][0].get_ref() << endl;}

  int get_index(unsigned long addr) {return addr % num_sets;}

  int get_tag(unsigned long addr) {return addr / num_sets;}

  unsigned long retrieve_addr(int way, int index) {return 0;}

  bool hit(ofstream& outfile, unsigned long addr);

  void update(ofstream& outfile, unsigned long addr);

private:
  int assoc;
  unsigned num_entries;
  int num_sets;
  Entry **entries;
};

Cache::Cache(int x, int y)
{
    num_entries = x;
    assoc = y;
    num_sets = num_entries / assoc;
    entries = (Entry**)malloc(sizeof(Entry *) * assoc);
    for (int i = 0; i < assoc; i++)
    {
        entries[i] = (Entry *)malloc(sizeof(Entry) * num_sets);
    }
    for (int i = 0; i < assoc; i++)
        for (int j = 0; j < num_sets; j++)
            entries[i][j].set_valid(false);
}

Cache::~Cache()
{
    free(entries);
}

bool Cache::hit(ofstream& outfile, unsigned long addr)
{
      int this_index = get_index(addr);
      int this_tag = get_tag(addr);
      int entry_tag = entries[0][this_index].get_tag();
      if (entry_tag == this_tag)
        return true;
      else
        return false;
  }

  void Cache::update(ofstream& outfile, unsigned long addr)
  {
      int this_index = get_index(addr);
      int this_tag = get_tag(addr);
      entries[0][this_index].set_tag(this_tag);
      entries[0][this_index].set_valid(true);
  }

int main(int argc, char*argv[]) {

if (argc < 4) {
    cout << "Usage: " << endl;
    cout << "   ./cache num_entries associativity filename" << endl;
    return 0;
  }

  /* get args; all args come in as strings; need to convert to int with atoi() */
  unsigned entries = atoi(argv[1]);
  unsigned assoc = atoi(argv[2]);

  string input_filename = argv[3];

  //if (argc < 2) {
  //  cout << "Usage: " << endl;
  // cout << "   ./file_process filename" << endl;
  //  return 0;
  //}

  /* get base file name from command-line */
  string filename = argv[1];

  /* create input and output filenames */
  //input_filename = filename + "_input";
  string output_filename = filename + "_output";

  /* create input and output files streams */
  ofstream output;
  ifstream input;

  /* open input stream for reading */
  input.open(input_filename.c_str());

  /* check if input stream has been succesfully opened; bail otherwise */
  if (!input.is_open()) {
    cerr << "Could not open input file " << input_filename << ". Exiting ..." << endl;
    exit(0);
  }

  unsigned long *nums = new unsigned long[MAX_SIZE];
  int count = 0;
  while (!input.eof() && count < MAX_SIZE) {
    input >> nums[count];
    count++;
  }

  /* done reading from input file; close the stream */
  input.close();

  Cache cache1(entries, assoc);

  /* open output file stream for writing */
  output.open("cache_sim_output.txt");

  /* print the args */
  cout << endl << "Number of entries: " << entries << endl;
  cout << "Associativity: " << assoc << endl;
  cout << "Input File Name: " << input_filename << endl;
  cout << "Results sent to: cache_sim_output.txt" << endl << endl;

  for (int i = 0; i < count; i++)
  {
      output << nums[i] << ": ";
      if (cache1.hit(output, nums[i]))
        output << "Hit" << endl;
      else
      {
         output << "Miss" << endl;
         cache1.update(output, nums[i]);
      }
  }

  /* no need to check if output file is open; we will create new file if it doesn't exist;
     overwrite otherwise */
  for (int i = 0; i < count; i++)


  /* close output stream */
  output.close();
  return 0;
}
