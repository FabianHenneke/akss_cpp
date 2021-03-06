#include "gtest/gtest.h"

#include "../src/matrix.h"
#include "../src/morphisms.h"

TEST(Cokernel, Diagonal)
{
  AbelianGroup Y(3, 0);
  MatrixQ f = {{0, 0, 0}, {0, 2, 0}, {0, 0, 3}};

  MatrixQList to_C;
  MatrixQList from_C;
  GroupWithMorphisms C =
      compute_cokernel(3, f, Y, MatrixQRefList(), MatrixQRefList());

  EXPECT_EQ(1, C.group.free_rank());
  ASSERT_EQ(1, C.group.tor_rank());
  EXPECT_EQ(1, C.group(0));
}

TEST(Kernel, Diagonal)
{
  AbelianGroup X(0, 2);
  X(0) = 1;
  X(1) = 2;

  AbelianGroup Y(0, 1);
  Y(0) = 2;

  MatrixQ f = {{5, 2}};

  MatrixQList to_K;
  MatrixQList from_K;

  MatrixQList from_X;
  MatrixQ id = {{1, 0}, {0, 1}};
  from_X.emplace_back(id);

  GroupWithMorphisms K =
      compute_kernel(5, f, X, Y, MatrixQRefList(), ref(from_X));

  EXPECT_EQ(0, K.group.free_rank());
  ASSERT_EQ(1, K.group.tor_rank());
  EXPECT_EQ(1, K.group(0));

}

TEST(Morphism, Equal)
{
	MatrixQ f = {{2,1},{5,2}};
	MatrixQ g = {{0,1},{1,2}};
	AbelianGroup Y(0,2);
	Y(0) = 1;
	Y(1) = 2;

	EXPECT_TRUE(morphism_equal(2,f,g,Y));
}

TEST(Morphism, Zero) {
	AbelianGroup Y(0,2);
	Y(0) = 1;
	Y(1) = 2;

	MatrixQ h = {{2,4,0},{12,0,8}};
	EXPECT_TRUE(morphism_zero(2,h,Y));

}


//TEST(Image, Diagonal) {
//	AbelianGroup X(0,2);
//	X(0) = 2;
//	X(1) = 2;
//
//	AbelianGroup Y(0,2);
//	Y(0) = 2;
//	Y(1) = 2;
//
//	MatrixQ f = {{0,6},{0,0}};
//
//	MatrixQList to_I;
//	MatrixQList from_I;
//	AbelianGroup I = compute_image(3,f,X,Y,to_I, from_I);
//
//	EXPECT_EQ(0,I.free_rank());
//	ASSERT_EQ(1,I.tor_rank());
//	EXPECT_EQ(1,I(0));
//}
