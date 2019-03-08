// Fill out your copyright notice in the Description page of Project Settings.

#include "MyMeshComponent.h"
#include <VertexFactory.h>
#include "DynamicMeshBuilder.h"

class FMyVertexBuffer : public FVertexBuffer
{
public:
    TArray<FVector> Vertices;

    virtual void InitRHI() override
    {
        FRHIResourceCreateInfo CreateInfo;
        VertexBufferRHI = RHICreateVertexBuffer(Vertices.Num() * sizeof(FVector), BUF_Static, CreateInfo);

        // Copy the vertex data into the vertex buffer.
        void* VertexBufferData = RHILockVertexBuffer(VertexBufferRHI, 0, Vertices.Num() * sizeof(FVector), RLM_WriteOnly);
        FMemory::Memcpy(VertexBufferData, Vertices.GetData(), Vertices.Num() * sizeof(FVector));
        RHIUnlockVertexBuffer(VertexBufferRHI);
    }
};

class FMyIndexBuffer : public FIndexBuffer
{
public:
    TArray<int32> Indices;


    virtual void InitRHI() override
    {
        FRHIResourceCreateInfo CreateInfo;
        IndexBufferRHI = RHICreateIndexBuffer(sizeof(int32), Indices.Num() * sizeof(int32), BUF_Static, CreateInfo);

        // Write the indices to the index buffer.
        void* Buffer = RHILockIndexBuffer(IndexBufferRHI, 0, Indices.Num() * sizeof(int32), RLM_WriteOnly);
        FMemory::Memcpy(Buffer, Indices.GetData(), Indices.Num() * sizeof(int32));
        RHIUnlockIndexBuffer(IndexBufferRHI);
    }

};

class ENGINE_API FMySceneProxy : public FPrimitiveSceneProxy
{
private:
    TArray<FDynamicMeshVertex> Vertices;
    TArray<uint32> Indices;
    FMyVertexBuffer VertexBuffer;
    FMyIndexBuffer IndexBuffer;

public:
	UPROPERTY()
    UMaterial* TheMaterial;

    FMySceneProxy(UMyMeshComponent * Component)
        :FPrimitiveSceneProxy(Component),
        Indices(Component->Indices),
        TheMaterial(Component->TheMaterial)
    {

        //Need to copy the FDynamicMeshVertex and index buffers from the component
        VertexBuffer = FMyVertexBuffer();
        IndexBuffer = FMyIndexBuffer();

        for (FVector Vertex : Component->Vertices)
        {
            Vertices.Add(FDynamicMeshVertex(Component->GetComponentLocation() + Vertex));
        }

    };

    virtual FPrimitiveViewRelevance GetViewRelevance(const FSceneView* View)  const override
    {
        FPrimitiveViewRelevance Result;
        Result.bDynamicRelevance = true;
        Result.bDrawRelevance = true;
        Result.bNormalTranslucencyRelevance = true;
        return Result;
    }

    virtual void GetDynamicMeshElements(const TArray<const FSceneView*>& Views, 
                                        const FSceneViewFamily& ViewFamily, 
                                        uint32 VisibilityMap, 
                                        FMeshElementCollector& Collector) const override
    {
        for (int32 ViewIndex = 0; ViewIndex < Views.Num(); ViewIndex++)
        {

            FDynamicMeshBuilder MeshBuilder(ERHIFeatureLevel::Type::ES2);

            if (Vertices.Num() == 0)
            {
                return;
            }

            MeshBuilder.AddVertices(Vertices);
            MeshBuilder.AddTriangles(Indices);

            MeshBuilder.GetMesh(FMatrix::Identity, new FColoredMaterialRenderProxy(TheMaterial->GetRenderProxy(false), FLinearColor::Gray), GetDepthPriorityGroup(Views[ViewIndex]), true, true, ViewIndex, Collector);

        }
    }


    void OnTransformChanged() override
    {
        VertexBuffer.ReleaseResource();
        IndexBuffer.ReleaseResource();
    }


    uint32 GetMemoryFootprint(void) const override
    {
        return sizeof(*this);
        //this also needs to return the size of the arrays I'm thinking
    }

	// Returns value for sorting purposes
	SIZE_T GetTypeHash(void) const override
	{
		return 0;
	}
	

    virtual ~FMySceneProxy() {};

};

FPrimitiveSceneProxy * UMyMeshComponent::CreateSceneProxy()
{
    FPrimitiveSceneProxy * Proxy = NULL;
    //Proxy = new FMySceneProxy(this);
    return Proxy;
}

UMyMeshComponent::UMyMeshComponent()
{

	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Engine/BasicShapes/BasicShapeMaterial'"));

	if (Material.Object != NULL)
	{
		TheMaterial = (UMaterial*)Material.Object;
	}

	Vertices.Add(FVector(10, 0, 0));
	Vertices.Add(FVector(0, 10, 0));
	Vertices.Add(FVector(0, 0, 10));
	Indices.Add(0);
	Indices.Add(1);
	Indices.Add(2);
}
