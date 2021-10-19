#include <WinInet.h>
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib, "wininet.lib")
#include <string>

//downloader parser
std::string ReplaceAllData(std::string subject, const std::string& search,
	const std::string& replace) {
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != std::string::npos) {
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return subject;
}

std::string DownloadURL(const char* URL) { 
	HINTERNET interwebs = InternetOpenA("Mozilla/5.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);
	HINTERNET urlFile;
	std::string rtn;
	if (interwebs) {
		urlFile = InternetOpenUrlA(interwebs, URL, NULL, NULL, NULL, NULL);
		if (urlFile) {
			char buffer[2000];
			DWORD bytesRead;
			do {
				InternetReadFile(urlFile, buffer, 2000, &bytesRead);
				rtn.append(buffer, bytesRead);
				memset(buffer, 0, 2000);
			} while (bytesRead);
			InternetCloseHandle(interwebs);
			InternetCloseHandle(urlFile);
			std::string p = ReplaceAllData(rtn, "|n", "\r\n");
			return p;
		}
	}
	InternetCloseHandle(interwebs);
	std::string p = ReplaceAllData(rtn, "|n", "\r\n");
	return p;
}

//memory protect
void x(int f)
{
  MessageBoxA(NULL, "YOU GOT SCAMMED!", "LOL", NULL);
}

//my addies
DWORD deserializer = 0;
DWORD spawn = 0;
DWORD print = 0;
#define print_ccv __fastcall
#define spawn_ccv __stdcall
#define deserializer __cdecl

//ofset
using luau_deserializer_usage = int(deserializer*)(DWORD a1, const char* a2, const char* a3, int a4, int a5);
luau_deserializer_usage luau_deserializer = (luau_deserializer_usage)(x(deserializer));

using lua_spawn_usage = int(spawn_ccv*)(int a1);
lua_spawn_usage lua_spawn = (r_spawn_typedef)(x(spawn));

//updater
void Update()
{
  if (deserializer == NULL && spawn == NULL && print == NULL)
  {
    MessageBoxA(NULL, "Preparing to update 3 offset(s)", "Preparing Update", NULL);
  }
  else
  {
    MessageBoxA(NULL, "Error occurred!\nMaybe one of the offsets are not NULL?\nUnknown error please review the code.\n-lol", "Oops", NULL);
    //error means that one of the addresses got updated, internet issue or the dll died so RIP>
  }
}

//done
