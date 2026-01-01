import matplotlib.pyplot as plt
import matplotlib.patches as patches


def draw_linked_list(values):
    """
    Draw a simple visualization of a linked list.

    values: Python list representing the list snapshot
    """

    fig, ax = plt.subplots()

    # Layout parameters
    x = 0
    y = 0
    box_width = 1.5
    box_height = 0.8
    spacing = 0.6

    # Draw HEAD pointer
    ax.text(
        x - 0.73,
        y + box_height / 2,
        "HEAD",
        ha="right",
        va="center",
        fontsize=12,
        fontweight="bold",
    )

    ax.arrow(
        x - 0.6,
        y + box_height / 2,
        spacing,
        0,
        head_width=0.08,
        head_length=0.12,
        length_includes_head=True,
    )

    # Manual index
    i = 0

    for value in values:
        # Draw the node box
        rect = patches.Rectangle((x, y), box_width, box_height, fill=False)
        ax.add_patch(rect)

        # Draw the value inside the box
        ax.text(
            x + box_width / 2,
            y + box_height / 2,
            str(value),
            ha="center",
            va="center",
            fontsize=12,
        )

        # Draw arrow to next node (if not the last one)
        if i < len(values) - 1:
            ax.arrow(
                x + box_width,
                y + box_height / 2,
                spacing,
                0,
                head_width=0.08,
                head_length=0.12,
                length_includes_head=True,
            )

        # Move x position for the next node
        x += box_width + spacing
        i += 1

    ax.arrow(
        x - spacing,
        y + box_height / 2,
        0.4,
        0,
        head_width=0.08,
        head_length=0.12,
        length_includes_head=True,
    )

    # Draw NULL label at the end
    ax.text(x - 0.1, y + box_height / 2, "NULL", ha="left", va="center", fontsize=12)

    ax.set_xlim(-1.5, x + 1.5)

    ax.set_aspect("equal")
    ax.axis("off")
    plt.title("Linked List Visualization")
    plt.savefig("linked_list.png")
    plt.close()


if __name__ == "__main__":
    draw_linked_list([10, 20, 30])
