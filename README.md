# 포켓몬스터 루비 & 사파이어

디컴파일 프로젝트([pokeruby](https://github.com/pret/pokeruby)) 기반의 한국어화 프로젝트입니다.

## 사용된 폰트

- 알님의 [에슘길체](https://cafe.naver.com/hansicgu/1996)
- quiple님의 [갈무리체](https://github.com/quiple/galmuri)

## 빌드 방법

윈도우 WSL(Ubuntu)을 기준으로 설명합니다.

### 프로젝트 복사

```sh
git clone https://github.com/poketony/pokeruby-kr
```

### 개발 도구 설치

#### devkitPro

(1) 아래 명령어를 입력하여 `dkp-pacman`을 설치합니다.  
(참조: https://devkitpro.org/wiki/devkitPro_pacman)

```sh
wget https://apt.devkitpro.org/install-devkitpro-pacman
chmod +x ./install-devkitpro-pacman
sudo ./install-devkitpro-pacman

sudo ln -s /proc/self/mounts /etc/mtab
```

(2) 명령어를 입력하여 개발 도구를 설치합니다.

```sh
sudo pacman -Sy
sudo pacman -S gba-dev
```

#### libpng 설치

```sh
sudo apt install libpng-dev
```

#### 컴파일러 설치 (agbcc)

(1) 아래 명령어를 실행하여 프로젝트를 받습니다.

```sh
git clone https://github.com/pret/agbcc

# 추후에 컴파일러가 호환되지 않을 경우 아래 명령어를 추가로 실행해주세요.
git checkout bfa92a1c98ce039a7df833beefa612fea65d3874
```

(2) 명령어를 입력하면 컴파일러 빌드가 진행됩니다.  
초기 빌드에 오류가 날 수도 있습니다. 그런경우 아래 명령어를 다시 한 번 더 실행해주세요.

```sh
cd agbcc
./build.sh
```

(3) 아래 명령어를 실행하면 컴파일러 준비 완료.

```sh
./install.sh ../pokeruby-kr
```

### 빌드

원하는 항목을 입력하여 실행합니다.

```sh
# 기본 빌드 (루비 버전)
make

# 루비 버전 빌드
make ruby
make ruby_debug
make ruby_modern
make ruby_modern_debug

# 사파이어 버전 빌드
make sapphire
make sapphire_debug
make sapphire_modern
make sapphire_modern_debug
```
