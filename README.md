# 1. Build mssl
## 1.1. CMake 설치
[홈페이지](https://cmake.org/download/)에 들어가서 platform에 맞는 Binary distribution을 다운받고 실행시키면 설치가 완료된다.

## 1.2. CMake 실행
1. CMake(cmake-gui)를 실행
2. Where is the source code에 mssl/library build 폴더 선택
3. Where to build the binaries에 mssl/library build/bin 폴더 선택
4. Configure 선택 >> Specify the generator for this project >> library를 사용하고자 하는 플랫폼 선택 >> Finish
5. Generate

## 1.3 Build library
### Visual studio의 경우
1. library build >> bin >> mssl.sln 실행
2. debug x64환경에서 빌드
3. relaese x64환경에서 빌드
4. mssl/library build/lib 폴더에 `mssl_release.lib`, `mssl_debug.lib` 생성 완료

# 2. Initial Setting
1. 사용하고자 하는 프로젝트의 `.vcxproj`가 있는 위치에 lib 폴더 생성후 mssl 폴더 생성
2. 생성한 project/lib/mssl 폴더안에 mssl/library build/lib 폴더에 있는 `mssl_release.lib`, `mssl_debug.lib` 복사
3. lib/mssl 폴더안에 mssl/src 폴더를 복사

project/lib 폴더관련 트리구조는 다음과 같아야 한다.
```
└─lib
    └─mssl
        │  mssl_debug.lib
        │  mssl_release.lib
        │
        └─src
                String_Editor.h
```

# 3. Visual Studio Setting Guide

1. 프로젝트 >> 속성 >> 일반 >> 플랫폼 도구 집합 >> C++17 이상
2. 프로젝트 >> 속성 >> 링커 >> 일반 >> 추가 라이브러리 디렉터리 >> 아래 내용 입력
```
$(ProjectDir)lib/mssl
```
3.  프로젝트 >> 속성 >> 링커 >> 입력 >> 추가종속성 >> 편집 >> 아래 내용 입력


```
(구성: debug)
mssl_debug.lib

(구성: release)
mssl_release.lib
```

# 사용법
1. String_Editor.h에 가서 지원하는 함수 중 필요한 함수가 있는지 살펴보기
2. 필요한 함수의 사용방법을 모르겠는 경우
   1. mssl/test 폴더로 이동
   2. 필요한 함수가 속해있는 test 파일을 열기
   3. 함수 검색후, test 내용을 보고 사용법 파악
3. 사용하고자 하는 cpp 파일에서 아래 내용 입력후 사용
```
#include "lib/mssl/src/String_Editor.h"
```

