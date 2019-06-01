#include <gtest.h>
#include <TTextLink.h>


TEST(TTextLink, can_init_memory)
{
  TTextLink* a;
  ASSERT_NO_THROW(a->InitMemory(100));
}

TEST(TTextLink, can_use_memory)
{
  TTextLink* a;
  a->InitMemory(100);
  ASSERT_NO_THROW(a = new TTextLink(1));
}

TEST(TTextLink, can_delete_memory)
{
  TTextLink* a;
  a->InitMemory(100);
  a = new TTextLink(1);
  ASSERT_NO_THROW(delete a);
}

TEST(TTextLink, can_use_assigment)
{
  TTextLink a(3), b(3);
  a.SetD('M');
  b.SetD('W');
  a = b;
  EXPECT_EQ(a.GetD(), 'W');
}


TEST(TTextLink, can_clone_assigment)
{
  TTextLink a(3), b(2), *c;
  a.SetD('M');
  b.SetD('W');
  b.SetDown(&a);
  c = b.Clone();
  EXPECT_NE(c->GetDown(), b.GetDown());
}

TEST(TTextLink, can_convert_to_string)
{
  TTextLink a("Jonny");
  int flag = 1;
  char* res = a.ToStr();
  char* exp = "Jonny";
  for (int i = 0; i < strlen(exp); i++)
  {
    if (res[i] != exp[i])
      flag = 0;
  }
  EXPECT_EQ(flag, 1);
}

TEST(TTextLink, can_add_letter)
{
  TTextLink a("DON");
  a += 'T';
  int flag = 1;
  char* res = a.ToStr();
  char* exp = "DONT";
  for (int i = 0; i < strlen(exp); i++)
  {
    if (res[i] != exp[i])
      flag = 0;
  }
  EXPECT_EQ(flag, 1);
}

TEST(TTextLink, can_add_sentense)
{
  TTextLink a("to");
  a += " be";
  int flag = 1;
  char* res = a.ToStr();
  char* exp = "to be";
  for (int i = 0; i < strlen(exp); i++)
  {
    if (res[i] != exp[i])
      flag = 0;
  }
  EXPECT_EQ(flag, 1);
}