// --> Christian A. Gillies
// Few comments describing the class Points2D

#ifndef CSCI335_HOMEWORK2_POINTS2D_H_
#define CSCI335_HOMEWORK2_POINTS2D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>


namespace teaching_project {
// Place comments that provide a brief explanation of this class and its sample usage:
// Manages arrays of 2d points implemented as 2d arrays
template<typename Object>
class Points2D {
 public:
  // Default "big five" -- you have to alter them for your assignment.
  // That means that you will remove the "= default" statement.
  //  and you will provide an implementation for it.

  // Zero-parameter constructor. 
  // Set size to 0.
  Points2D(): size_(0), sequence_{new std::array<Object,2>[0]}
  {
    
    //std::cout<< "Zero parameter constructor"<< std::endl;
  }

  // Copy-constructor.
  Points2D(const Points2D &rhs)
  {
    //std::cout<< "Copy constructor"<< std::endl;
    //std::cout<<" []";
    //std::cout<<"->"<< rhs<< std::endl;
    //delete [] sequence_;
    size_=rhs.size();
    sequence_=new std::array<Object,2>[size_];
    for(int i =0;i<size_;i++)
    {
      sequence_[i]=rhs[i];
    }

  }
  // Copy-assignment. If you have already written
  // the copy-constructor and the move-constructor
  // you can just use:
  // {
  // Points2D copy = rhs; 
  // std::swap(*this, copy);
  // return *this;
  // }
  Points2D& operator=(const Points2D &rhs)
  {
     
    Points2D copy = rhs; 
    std::swap(*this, copy);
    return *this;

  }

  // Move-constructor. 
  Points2D(Points2D &&rhs)
  {
    sequence_= std::move(rhs.sequence_);
    size_= rhs.size();
  }

  // Move-assignment.
  // Just use std::swap() for all variables.
  Points2D& operator=(Points2D &&rhs) {
    std::swap(this->sequence_,rhs.sequence_);
    std::swap(this->size_,rhs.size_);
  }
  ~Points2D() 
  {
    //delete sequence_;
    // std::array automatically frees it memory
  }

  // End of big-five.

  // One parameter constructor.
  Points2D(const std::array<Object, 2>& item) {
    //std::cout<< "\n One parameter constructor"<< std::endl;
    
    sequence_= new std::array<Object,2>[0];
    //std::cout<< " Copy"<< std::endl;
    sequence_[0]=item;
    size_=item.size();
    // Provide code.
  }

  // Read a chain from standard input.
  void ReadPoints2D() {
    // Part of code included (without error checking).
    std::string input_line;
    std::getline(std::cin, input_line); 
    std::stringstream input_stream(input_line);
    // std::cout<< "good?";
    if (input_line.empty()) return;
    // Read size of sequence (an integer).
    int size_of_sequence;
    input_stream >> size_of_sequence;
    //std::cout<<"Sequence Size: "<< size_of_sequence<<std::endl;
    sequence_ = new std::array<Object,2>[size_of_sequence];// Allocate space for sequence.
    size_=size_of_sequence;
    // Add code here.
    
    Object token;
    for (int i = 0 ;input_stream >> token; ++i) 
    {
      //std::cout<<"( Row:"<< i <<")"<<std::endl;
      //std::cout<<"\n("<< sequence_[i][0] <<","<< sequence_[i][1] <<")";
      sequence_[i][0]=token;// Read coordinates (x).
      input_stream >> token;
      sequence_[i][1]=token;// Read coordinates (y).
      std::cout<<"\n("<< sequence_[i][0] <<","<< sequence_[i][1] <<")";
      // Fill sequence_ here.
    }
    
  }

  size_t size() const {
    return this->size_;// Code missing.
  }

  // @location: an index to a location in the given sequence.
  // @returns the point at @location.
  // const version.
  // abort() if out-of-range.
  const std::array<Object, 2>& operator[](size_t location) const { 
    return sequence_[location];// Code missing.
  }

 //  @c1: A sequence.
 //  @c2: A second sequence.
 //  @return their sum. If the sequences are not of the same size, append the
 //    result with the remaining part of the larger sequence.
 friend Points2D operator+(const Points2D &c1, const Points2D &c2) {
  
  

  int min_size;// smaller of two sizes 
  if(c1.size_<c2.size_)
    min_size= c1.size_;
  else
    min_size= c2.size_;
  std::array<Object,2> *sum = new std::array<Object,2>[min_size];
  for(int i =0;i<min_size;i++)
  {
    
    sum[i][0] =c1.sequence_[i][0]+c2.sequence_[i][0];
    sum[i][1] =c1.sequence_[i][1]+c2.sequence_[i][1];
  }
  Points2D sum_seq{*sum};  
  return sum_seq;// Code missing.
 }

 // Overloading the << operator.
 friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points2d) {
   // Code missing.
   //std::cout<<"\n << called"<<std::endl;
  for(int i =0;i<some_points2d.size();i++)
  {
    
    std::cout <<" ("<< some_points2d[i][0]<< ", ";
    std::cout << some_points2d[i][1]<<")";//<<std::endl;
    
  }
   
 }
 
 private:
  // Sequence of points. 
  std::array<Object, 2> *sequence_;
  // Size of the sequence.
  size_t size_;

};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK2_POINTS2D_H_
