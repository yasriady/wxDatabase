#ifndef __POSTGRESQL_DATABASE_LAYER_H__
#define __POSTGRESQL_DATABASE_LAYER_H__

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif
 
#include "../database.h"
 

#ifndef DONT_USE_DYNAMIC_DATABASE_LAYER_LINKING
class wxDynamicPostgresInterface;
#endif


class WXDLLIMPEXP_DATABASELAYER wxPostgresDatabase : public wxDatabase
{
public:
  // Information that can be specified for a PostgreSQL database
  //  host or hostaddr
  //  port
  //  dbname
  //  user
  //  password
  // ctor
  wxPostgresDatabase();
  wxPostgresDatabase(const wxString& strDatabase);
  wxPostgresDatabase(const wxString& strServer, const wxString& strDatabase);
  wxPostgresDatabase(const wxString& strDatabase, const wxString& strUser, const wxString& strPassword);
  wxPostgresDatabase(const wxString& strServer, const wxString& strDatabase, const wxString& strUser, const wxString& strPassword);
  wxPostgresDatabase(const wxString& strServer, int nPort, const wxString& strDatabase, const wxString& strUser, const wxString& strPassword);
  wxPostgresDatabase(void* pDatabase) { m_pDatabase = pDatabase; }

  // dtor
  virtual ~wxPostgresDatabase();

  // open database
  virtual bool Open();
  virtual bool Open(const wxString& strDatabase);
  virtual bool Open(const wxString& strServer, const wxString& strDatabase);
  virtual bool Open(const wxString& strDatabase, const wxString& strUser, const wxString& strPassword);
  virtual bool Open(const wxString& strServer, const wxString& strDatabase, const wxString& strUser, const wxString& strPassword);
  virtual bool Open(const wxString& strServer, int nPort, const wxString& strDatabase, const wxString& strUser, const wxString& strPassword);

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

  // PreparedStatement support
  virtual wxPreparedStatement* PrepareStatement(const wxString& strQuery);

  // Database schema API contributed by M. Szeftel (author of wxActiveRecordGenerator)
  virtual bool TableExists(const wxString& table);
  virtual bool ViewExists(const wxString& view);
  virtual wxArrayString GetTables();
  virtual wxArrayString GetViews();
  virtual wxArrayString GetColumns(const wxString& table);

  void SetPort(int nPort);

  static int TranslateErrorCode(int nCode);
  static bool IsAvailable();

private:
#ifndef DONT_USE_DYNAMIC_DATABASE_LAYER_LINKING
  wxDynamicPostgresInterface* m_pInterface;
#endif
  wxString m_strServer;
  wxString m_strDatabase;
  wxString m_strUser;
  wxString m_strPassword;
  wxString m_strPort;

  void* m_pDatabase;
};

#endif // __POSTGRESQL_DATABASE_LAYER_H__

