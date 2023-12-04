// #ifndef DRAW_IMGUI_HPP
// #define DRAW_IMGUI_HPP

#pragma once 

#include <stdio.h>
#include "nQueens_solver.hpp"


extern int NN;
extern std::vector<int> state;
extern std::vector<std::vector<int>> board;

// void drawBoard(std::vector<std::vector<int>>& board, std::vector<int>& state);

void ShowExampleAppLayout(bool* p_open);

// Dear ImGui: standalone example application for DirectX 11

// Learn about Dear ImGui:
// - FAQ                  https://dearimgui.com/faq
// - Getting Started      https://dearimgui.com/getting-started
// - Documentation        https://dearimgui.com/docs (same as your local docs/ folder).
// - Introduction, links and more at the top of imgui.cpp

#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <d3d11.h>
#include <tchar.h>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include <stdexcept>

// Data
static ID3D11Device *g_pd3dDevice = nullptr;
static ID3D11DeviceContext *g_pd3dDeviceContext = nullptr;
static IDXGISwapChain *g_pSwapChain = nullptr;
static UINT g_ResizeWidth = 0, g_ResizeHeight = 0;
static ID3D11RenderTargetView *g_mainRenderTargetView = nullptr;



int drawBoard();

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);

void CleanupDeviceD3D();

void CreateRenderTarget();

void CleanupRenderTarget();

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// #endif
