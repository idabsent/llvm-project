#ifndef LLDB_TOOLS_LLDB_VSCODE_PIPEWSC_H
#define LLDB_TOOLS_LLDB_VSCODE_PIPEWSC_H

#include "llvm/ADT/StringRef.h"
#include "lldb/Utility/Status.h"
#include "lldb/Host/windows/windows.h"

#include <string>

class PipeWSC {
public:
  PipeWSC();
  ~PipeWSC();

  lldb_private::Status Create(llvm::StringRef name);
  lldb_private::Status OpenExist(llvm::StringRef name);
  lldb_private::Status Connect();
  lldb_private::Status Disconnect();

  void Close();

  lldb_private::Status Write(void const* buff, size_t bytes_count, size_t& bytes_writed);
  lldb_private::Status Read(void* buff, size_t buff_size, size_t& bytes_readed) const;

  llvm::StringRef GetPath() const;

private:
  HANDLE m_pipe;
  std::string m_path;
};

#endif