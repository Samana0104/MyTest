// �������̴� ��ȯ���� ������ float4 �� �̾�� �Ѵ�.
// �ø�ƽ(�ṉ̀���) : SV_POSITION, POSITION) 
struct VS_In
{
	float2 p : POS;
	float4 c : COLOR;
	float2 t : TEX;
};

struct VS_Out
{
	float4 p : SV_POSITION;// �ݵ�� float4
	float4 c  :COLOR0;//COLOR1;
	float2 t  :TEXCOORD0; // ~ TEXCOORD15
};

VS_Out VSMain( VS_In vsIn) 
{
    VS_Out vsOut = (VS_Out) 0;
    vsOut.p = float4(vsIn.p.x, vsIn.p.y, 0, 1);
    vsOut.c = vsIn.c;
    vsOut.t = vsIn.t;
    return vsOut;
}
/*float4 VSMain( float2 p : POS, float4 c:COLOR) : SV_POSITION
{
  return float4(p.x,p.y,0.5f,1.0f);
}*/