[English](README.md)

# miniRT

MiniLibX를 사용해 C로 구현한 레이 트레이서입니다. `.rt` 파일로 정의한 3D 씬을 렌더링합니다. 42 Seoul 팀 프로젝트 — 2인 팀.

<!-- 렌더링 결과 스크린샷을 여기에 추가하세요 -->

## 기능

- **오브젝트** — 구(sphere), 평면(plane), 원기둥(cylinder)
- **조명** — 환경광 + 난반사 조명 및 그림자
- **카메라** — 위치, 방향, 시야각(FOV) 설정 가능
- **씬 파일** — 오브젝트, 조명, 카메라를 정의하는 `.rt` 텍스트 형식

```
A  0.1  255,255,255          # 환경광
C  0,0,200  0,0,-1  70       # 카메라 (위치, 방향, FOV)
L  60,60,120  0.8  255,255,255
sp 0,0,0  20  255,0,0        # 구 (중심, 지름, 색상)
pl 0,-20,0  0,1,0  200,200,200
cy 0,20,0  0,1,0  10  30  0,0,255
```

## 빌드 및 실행

```bash
make
./miniRT example.rt
```

Linux + MiniLibX 필요.

## 참고 자료

레이 트레이싱 기초: [Ray Tracing in One Weekend (한국어)](https://github.com/sejinpark12/RayTracing_in_One_Weekend_Kor)

## 팀

| | GitHub | 담당 |
|---|---|---|
| **sypyeon** | [@sypyeon](https://github.com/sypyeon) | 광선-오브젝트 교차 계산 · Phong 조명 · 뷰포트 |
| **jaehylee** | [@jaehylee](https://github.com/jaehylee) | `.rt` 씬 파일 파싱 · union 기반 오브젝트 자료구조 |
