#include <gtest.h>
#include <TText.h>


TEST(TText, can_create_text)
{
  ASSERT_NO_THROW(TText t);
}

TEST(TText, can_initalize_text)
{
  ASSERT_NO_THROW(TText t("TESTMESSAGE TEST AAA BB C"));
}

TEST(TText, can_isert_link_down_text)
{
  TText txt;
  TTextLink* link = new TTextLink("NOOO");
  ASSERT_NO_THROW(txt.InsertDown(link));
}

TEST(TText, can_insert_string_down)
{
  TText txt;
  ASSERT_NO_THROW(txt.InsertDown("Gendaaaaaalf"));
}

TEST(TText, can_go_down_link)
{
  TText txt;
  TTextLink* link = new TTextLink("NOOO");
  txt.InsertDown(link);
  txt.GoDownLink();
  EXPECT_EQ(txt.GetCurrent(), link);
}

TEST(TText, can_insert_link_next)
{
  TText txt;
  TTextLink* link = new TTextLink("Luke");
  TTextLink* nextlink = new TTextLink("I am your father");
  txt.InsertDown(link);
  txt.GoDownLink();
  ASSERT_NO_THROW(txt.InsertNext(nextlink));
}

TEST(TText, can_insert_string_next)
{
  TText txt;
  txt.InsertDown("Luke");
  txt.GoDownLink();
  ASSERT_NO_THROW(txt.InsertNext("I am your father"));
}

TEST(TText, can_go_next_link)
{
  TText txt;
  TTextLink* link = new TTextLink("Luke");
  TTextLink* nextlink = new TTextLink("I am your father");
  txt.InsertDown(link);
  txt.GoDownLink();
  txt.InsertNext(nextlink);
  txt.GoNextLink();
  EXPECT_EQ(txt.GetCurrent(), nextlink);
}


TEST(TText, can_delete_link_next)
{
  TText txt;
  TTextLink* link = new TTextLink("Luke");
  TTextLink* nextlink = new TTextLink("I am your father");
  txt.InsertDown(link);
  txt.GoDownLink();
  txt.InsertNext(nextlink);
  ASSERT_NO_THROW(txt.DelNext());
}

TEST(TText, can_delete_string_down)
{
  TText txt;
  txt.InsertDown("Gendaaaaaalf");
  ASSERT_NO_THROW(txt.DelDown());
}

TEST(TText, can_use_memory_cleaner)
{
  TTextLink* a;
  TText txt;
  txt.InsertDown("Gendaaaaaalf");
//  a->InitMemory(20);
  for (int i = 0; i < 10; i++)
  {
    a = new TTextLink(1);
    delete a;
  }
  ASSERT_NO_THROW(a->MemCleaner(txt));
}
