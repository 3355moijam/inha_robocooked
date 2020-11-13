#pragma once
#include <fmod.hpp>
#pragma comment(lib,"fmodex_vc.lib")
#include <string>
#include <map>

#define g_SoundManager	SoundManager::GetInstance()

using namespace std;
using namespace FMOD;

class SoundManager : public CSingleton<SoundManager>
{
private:
	System * fmodSystem;

	Channel* bgmChannel;
	Channel* sfxChannel;

	Sound* bgm;
	map<string, Sound*> soundHash;

private:
	void init();

public:
	SoundManager();
	~SoundManager();

	void AddSFX(string path, string musicName);
	void AddBGM(string path);
	void PlaySFX(string soundName);
	void PlayBGM();
	void Stop();

	void Destroy();

};

