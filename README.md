# StreamUP Hotkey Display for OBS Studio

**StreamUP Hotkey Display** is an OBS Studio plugin that visualizes your keyboard and mouse inputs in real-time. Designed for developers, educators, and high-performance gamers, it provides a sleek, high-performance overlay that shows exactly what you're pressing including real-time mouse coordinates and scroll intensity.

## 🚀 The Internal Event Engine

The plugin has evolved from a simple text-source display to a high-performance **Internal Event Engine**. By leveraging the native **Browser Source** (CEF) API, events are now emitted directly into the browser's JavaScript environment.


https://github.com/user-attachments/assets/770859ee-223b-451b-b5c9-16d666b4fd8b


> [!NOTE]
> The original WebSocket-based architecture is still available in the [**websocket**](https://github.com/Andilippi/obs-streamup-hotkey-display/tree/websocket) branch for users who require remote network distribution.

| Feature | Direct Events (New) | WebSocket (Legacy) |
|---------|---------------------|-------------------|
| **Latency** | 0ms (Internal) | 5-20ms (Network) |
| **Config** | None Required | IP/Port/Auth |
| **Reliability** | Native / Built-in | TCP / Socket-based |

### 💎 Premium Browser Overlay
- **Modern Design**: JavaScript and CSS-driven animations.
- **True Zero-Config**: The plugin automatically targets your browser source. No manual IP or password setup is required.
- **Ultra Performance**: Input events are frame-perfect relative to OBS processing, bypassing the network stack entirely.

### 🖱 Elite Mouse Tracking
- **Real-time Position**: High-frequency tracking of your (X, Y) cursor coordinates (throttled to 50Hz for efficiency).
- **Scroll Speed & Direction**: Dynamically calculates and visualizes scroll velocity.
- **Selective Output**: Toggle exactly what data is sent to the overlay—capture everything or just specific actions.

### ⌨️ Comprehensive Key Capture
- **Complex Combinations**: Native support for all major modifiers (Ctrl, Alt, Shift, Cmd/Super).
- **Single Key Modes**: Optional capture for numpads, letters, symbols, and punctuation.
- **Custom Whitelisting**: Manually specify exactly which keys should be captured standalone.

### 🖥 Integrated OBS Dock
- **Live Preview**: Monitor your current combinations and history right inside the OBS UI.
- **One-Click Control**: Start/Stop monitoring and access settings directly from the dock.
- **Configurable History**: Track up to 50 recent combinations with adjustable auto-clear timers.

## 🔧 Technical Details

### Internal Browser API
The plugin emits events directly to the target browser source using the `emit_event` procedure.

**Event Name**: `streamup_hotkey_input`
**Payload**: Structured JSON containing key combinations, mouse position, actions, and scroll metadata.

### WebSocket API (Management)
Registered under the `streamup-hotkey-display` vendor for remote plugin management.

| Request | Description |
|---------|-------------|
| `get_status` | Returns capture status and last known combination. |
| `enable` / `disable` | Toggles the global input hooks. |
| `get_last_combination` | Retrieves the most recent combination. |

## 🏗 Build & Installation

### Requirements
- **Windows**: Windows 10/11
- **macOS**: 10.15+ (Requires Accessibility Permissions)
- **Linux**: X11 environment (Wayland supported via XWayland/XCB)

### Compiling
1. Clone this repository to `frontend/plugins/obs-streamup-hotkey-display`.
2. Add `add_subdirectory(obs-streamup-hotkey-display)` to your `frontend/plugins/CMakeLists.txt`.
3. Rebuild OBS Studio or build out-of-tree using provided CMake presets.

## 🤝 Support & Community

Built and maintained by **Andi**. If this plugin helps your workflow, consider supporting its continued development.

- [**Memberships**](https://andilippi.co.uk/pages/memberships) - Access all products and exclusive perks
- [**PayPal**](https://www.paypal.me/andilippi) - Support the developer
- [**Twitch**](https://www.twitch.tv/andilippi) - Tutorials and live dev sessions
- [**YouTube**](https://www.youtube.com/andilippi) - Streaming setup guides

---
*© 2026 StreamUP. Licensed under the GPL-2.0.*
