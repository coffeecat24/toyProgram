---

# 개인 프로젝트용 GitHub 사용 매뉴얼

이 매뉴얼은 GitHub 계정 생성부터 로컬에서 작업하고 변경사항을 원격 저장소에 반영하는 기본 워크플로우를 설명합니다.

---

## 1. 로컬 개발 환경 준비

### A. Git 설치

- Git을 설치하지 않았다면 [Git 공식 사이트](https://git-scm.com/)에서 운영체제에 맞는 설치 파일을 다운로드하여 설치합니다.

### B. Git 기본 설정

1. **터미널(또는 명령 프롬프트) 실행**  
2. 아래 명령어를 입력하여 본인의 정보를 Git에 등록합니다.
   ```bash
   git config --global user.name "Your Name"
   git config --global user.email "your.email@example.com"
   ```
   (여기서 `"Your Name"`과 `"your.email@example.com"`은 본인의 실제 이름과 이메일로 교체합니다.)

---

## 2. GitHub에서 새로운 저장소(Repository) 생성

1. **로그인 후 저장소 생성**  
   GitHub에 로그인한 후, 우측 상단의 **+** 버튼을 클릭하고 **New repository**를 선택합니다.
2. **저장소 작성**  
   - **Repository name**: 저장소 이름을 입력합니다.  
   - **Description**: 선택 사항으로 저장소에 대한 간단한 설명을 추가할 수 있습니다.  
   - **Public/Private**: 개인적으로 사용할 프로젝트이므로, 원격 백업용이거나 특정 파일 관리 목적이라면 private으로 설정할 수 있습니다.
3. **초기화 옵션 선택 (선택 사항)**  
   README 파일, .gitignore 파일, 라이선스 등을 추가할 수 있는데, 처음이라면 README 파일만 추가해도 좋습니다.
4. **Create repository** 버튼을 눌러 저장소를 생성합니다.

---

## 3. 로컬 저장소와 연결하기

### A. 저장소 복제(Clone)

1. **저장소 URL 확인**  
   새로 생성한 저장소 페이지의 **Code** 버튼을 클릭하여 HTTPS URL을 복사합니다.
2. **터미널에서 저장소 복제**  
   ```bash
   cd /원하는/작업/디렉토리
   git clone https://github.com/yourusername/repositoryname.git
   ```
   (복사한 URL과 저장소 이름을 실제 값으로 대체합니다.)
3. **저장소 디렉토리 이동**
   ```bash
   cd repositoryname
   ```

---

## 4. 개인 프로젝트를 위한 기본 Git 워크플로우

### A. 파일 수정 및 변경사항 기록

1. **코드 편집**  
   본인이 사용하는 코드 에디터로 프로젝트 파일을 수정합니다.
2. **변경사항 확인**  
   터미널에서 아래 명령어를 실행하여 수정된 파일 확인:
   ```bash
   git status
   ```
3. **파일 스테이징**  
   모든 변경사항을 스테이징 영역에 추가:
   ```bash
   git add .
   ```
4. **커밋 생성**  
   변경 사항을 기록하면서 커밋 메시지를 작성:
   ```bash
   git commit -m "작업 내용에 대한 간략한 설명"
   ```

### B. 원격 저장소에 변경사항 업로드

- **Push**  
  로컬 커밋을 원격 저장소의 기본(branch 이름이 `main` 또는 `master`)에 업로드:
  ```bash
  git push origin main
  ```
  (기본 브랜치 이름이 다를 경우, 해당 브랜치 이름으로 변경합니다.)

### C. 최신 변경사항 불러오기

- **Pull**  
  GitHub 상의 저장소에 직접 수정한 내용이나 다른 기기에서 변경한 내용이 있다면 아래 명령어로 최신 상태로 업데이트:
  ```bash
  git pull origin main
  ```

---

## 5. (선택 사항) 브랜치 관리 – 실험 및 기능 추가 시

개인 프로젝트에서도 실험적인 변경 사항을 main 브랜치와 분리하여 관리하고 싶다면 브랜치를 활용해 보세요.

1. **새 브랜치 생성 및 전환**
   ```bash
   git checkout -b new-feature
   ```
2. **변경 후 커밋**  
   필요한 변경 작업을 수행한 후 일반 워크플로우(스테이징 → 커밋)를 진행합니다.
3. **main 브랜치로 전환 후 병합 (원할 경우)**
   ```bash
   git checkout main
   git merge new-feature
   ```
4. **브랜치 삭제 (병합 완료 후)**
   ```bash
   git branch -d new-feature
   ```

---