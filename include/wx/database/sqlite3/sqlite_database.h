#ifndef _WX_DATABASE_SQLITE_DATABASE_H_
#define _WX_DATABASE_SQLITE_DATABASE_H_

#include "wx/database/wxprec.h"

class wxPreparedStatement;

class WXDLLIMPEXP_DATABASE wxSqliteDatabase : public wxDatabase
{
public:
  // ctor()
  wxSqliteDatabase();
  wxSqliteDatabase(const wxString& strDatabase, bool mustExist = false);
  wxSqliteDatabase(void* pDatabase) { m_pDatabase = pDatabase; }
  
  // dtor()
  virtual ~wxSqliteDatabase();
  
  // open database
  virtual bool Open(const wxString& strDatabase);
  virtual bool Open(const wxString& strDatabase, bool mustExist);
  
  // close database  
  virtual bool Close();
  
  // Is the connection to the database open?
  virtual bool IsOpen();

  // transaction support
  virtual void BeginTransaction();
  virtual void Commit();
  virtual void RollBack();
  
  // query database
  virtual int RunQuery(const wxString& strQuery, bool bParseQuery);
  virtual wxDatabaseResultSet* RunQueryWithResults(const wxString& strQuery);
  
  // wxPreparedStatement support
  virtual wxPreparedStatement* PrepareStatement(const wxString& strQuery);
  wxPreparedStatement* PrepareStatement(const wxString& strQuery, bool bLogForCleanup);
  
  // Database schema API contributed by M. Szeftel (author of wxActiveRecordGenerator)
  virtual bool TableExists(const wxString& table);
  virtual bool ViewExists(const wxString& view);
  virtual wxArrayString GetTables();
  virtual wxArrayString GetViews();
  virtual wxArrayString GetColumns(const wxString& table);
  virtual wxArrayString GetPKColumns(const wxString& table);

  static int TranslateErrorCode(int nCode);

private:
  
  //sqlite3* m_pDatabase;
  void* m_pDatabase;
};

#endif//_WX_DATABASE_SQLITE_DATABASE_H_

