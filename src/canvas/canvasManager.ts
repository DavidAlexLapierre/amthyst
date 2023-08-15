export class CanvasManager {
    public initCanvas(width: number, height: number, rootId?: string) {
        const root = rootId ? document.getElementById(rootId) : document.body;
        const canvas = document.createElement('canvas');
        canvas.width = width;
        canvas.height = height;
        canvas.style.background = 'rgba(20, 20, 20, 1.0)';
        root?.appendChild(canvas);
    }
}